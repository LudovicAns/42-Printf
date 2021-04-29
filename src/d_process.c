#include "ft_printf.h"

/*
 * Function: ft_custom_nbrlen					1/5
 * ----------------------------------------
 *   Count lenght of a number with (or not) negative sign.
 *
 *   nb: number to count
 *   take_neg: negative count mode
 *
 *   returns: lenght of the number depending of take_neg.
 */
static int	ft_custom_nbrlen(int nb, t_boolean take_neg)
{
	unsigned int	nui;
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nui = -nb;
		if (take_neg)
			i++;
	}
	else
		nui = nb;
	while (nui)
	{
		nui /= 10;
		i++;
	}
	return (i);
}

/*
 * Function: ft_custom_itoa						2/5
 * ----------------------------------------
 *   Convert integer to string without negative sign.
 *
 *   nb: number to convert
 *
 *   returns: string
 */
static char	*ft_custom_itoa(int nb)
{
	unsigned int	nui;
	char			*out;
	int				i;

	out = (char *)malloc(sizeof(char) * (ft_custom_nbrlen(nb, FALSE) + 1));
	if (!out)
		return (NULL);
	i = 0;
	if (nb < 0)
		nui = -nb;
	else
		nui = nb;
	i = ft_custom_nbrlen(nb, FALSE) - 1;
	while (nui)
	{
		out[i--] = (nui % 10) + '0';
		nui /= 10;
	}
	if (nb == 0)
		out[i] = '0';
	out[ft_custom_nbrlen(nb, FALSE)] = '\0';
	return (out);
}

/*
 * Function: get_print_size						3/5
 * ----------------------------------------
 *   Return correct final print size depending of differents parameters.
 *
 *   identifier: identifier
 *   nb: number to print
 *
 *   returns: final size
 */
static int	get_print_size(t_identifier identifier, int nb)
{
	int	size;

	if (identifier.has_print_settings
		&& identifier.print_settings.has_min_field_width
		&& identifier.print_settings.has_precision_width)
	{
		if (identifier.print_settings.precision_width
			> identifier.print_settings.min_field_width)
			size = identifier.print_settings.precision_width;
		else
			size = identifier.print_settings.min_field_width;
	}
	else if (identifier.has_print_settings)
	{
		if (identifier.print_settings.has_min_field_width)
			size = identifier.print_settings.min_field_width;
		else
			size = identifier.print_settings.precision_width;
	}
	else
		size = ft_custom_nbrlen(nb, TRUE);
	return (size);
}

/*
 * Function: get_precision_size					4/5
 * ----------------------------------------
 *   Return the size of precision.
 *
 *   identifier: identifier
 *
 *   returns: size of precision and 0 if no precision size.
 */
static int	get_precision_size(t_identifier identifier)
{
	int	psize;

	psize = 0;
	if (identifier.has_print_settings
		&& identifier.print_settings.has_precision_width)
		psize = identifier.print_settings.precision_width;
	return (psize);
}

static int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

static void	*get_funcomplete(t_identifier identifier)
{
	if (identifier.has_flag && identifier.flag.has_zero_filler)
	{
		if (identifier.flag.has_left_justify)
			return (print_space);
		else if (identifier.has_print_settings
			&& identifier.print_settings.has_precision_width)
			return (print_space);
		else
			return (print_zero);
	}
	return (print_space);
}

/*
 * Function: process_d							5/5
 * ----------------------------------------
 *   Process identifier using d argument type.
 *
 *   identifier: identifier
 *   args: arguments list
 * 
 *   i[0] : nb in args
 *   i[1] : total print size
 *   i[2] : precision size
 *   i[3] : count
 * 
 *   %-0*.*d
 *
 *   returns: number of printed chars.
 */
int	process_d(t_identifier identifier, va_list args)
{
	char	*number;
	int		i[4];
	int		(*complete)(int);

	i[0] = va_arg(args, int);
	i[1] = get_print_size(identifier, i[0]);
	i[2] = get_precision_size(identifier);
	i[3] = 0;
	number = ft_custom_itoa(i[0]);
	complete = get_funcomplete(identifier);
	if (i[0] < 0 && identifier.flag.has_zero_filler
		&& !(identifier.has_print_settings
			&& identifier.print_settings.has_precision_width))
		i[3] += print_char('-');
	if (i[0] >= 0 && identifier.flag.has_blank_on_positive)
		i[3] += print_space(1);
	if (identifier.has_flag && identifier.flag.has_left_justify)
	{
		if (i[0] < 0 && (!identifier.flag.has_zero_filler
				|| (identifier.has_print_settings
					&& identifier.print_settings.has_precision_width)))
			i[3] += print_char('-');
		if (i[0] >= 0 && identifier.flag.has_force_positive)
			i[3] += print_char('+');
		i[3] += print_zero(i[2] - ft_custom_nbrlen(i[0], FALSE));
		if (!(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0 && i[0] == 0))
			i[3] += print_string(number);
		if (i[3] < i[1])
			i[3] += complete(i[1] - i[3]);
	}
	else
	{
		if (ft_custom_nbrlen(i[0], FALSE) < i[1] && i[1] > i[2])
		{
			if (i[2] < ft_custom_nbrlen(i[0], FALSE))
			{
				if ((i[0] < 0 || (i[0] >= 0
							&& identifier.flag.has_force_positive))
					&& i[3] == 0)
					i[3] += complete((i[1] - i[3])
							- ft_abs(i[2] - ft_custom_nbrlen(i[0], FALSE)) - 1);
				else
					i[3] += complete((i[1] - i[3])
							- ft_abs(i[2] - ft_custom_nbrlen(i[0], FALSE)));
			}
			else
			{
				if ((i[0] < 0 || (i[0] >= 0
							&& identifier.flag.has_force_positive))
					&& i[3] == 0)
					i[3] += complete((i[1] - i[3]) - i[2] - 1);
				else
					i[3] += complete((i[1] - i[3]) - i[2]);
			}
		}
		if (i[0] < 0 && (!identifier.flag.has_zero_filler
				|| (identifier.has_print_settings
					&& identifier.print_settings.has_precision_width)))
			i[3] += print_char('-');
		if (i[0] >= 0 && identifier.flag.has_force_positive)
			i[3] += print_char('+');
		i[3] += print_zero(i[2] - ft_custom_nbrlen(i[0], FALSE));
		if (!(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0 && i[0] == 0))
			i[3] += print_string(number);
		else
			i[3] += complete(i[1] - i[3]);
	}
	free(number);
	return (i[3]);
}
