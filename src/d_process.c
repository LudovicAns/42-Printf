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
		size = ft_nbrlen(nb);
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

/*
 * Function: process_d							5/5
 * ----------------------------------------
 *   Process identifier using d argument type.
 *
 *   identifier: identifier
 *   args: arguments list
 *
 *   returns: number of printed chars.
 */
int	process_d(t_identifier identifier, va_list args)
{
	char	*number;
	int		i;
	int		size;
	int		psize;
	int		count;

	i = va_arg(args, int);
	number = ft_custom_itoa(i);
	size = get_print_size(identifier, i);
	psize = get_precision_size(identifier);
	count = 0;
	if (identifier.has_flag && identifier.flag.has_blank_on_positive
		&& i > 0 && !identifier.flag.has_force_positive)
	{
		count += print_space(1);
		size--;
	}
	if (identifier.has_flag && identifier.flag.has_left_justify)
	{
		if (i < 0)
			count += print_char('-');
		if (identifier.has_flag
			&& identifier.flag.has_force_positive && i >= 0)
		{
			count += print_char('+');
			size--;
		}
		count += print_zero(psize - ft_custom_nbrlen(i, FALSE));
		if (!(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0)
			|| i != 0)
			count += print_string(number);
		if (psize > ft_custom_nbrlen(i, FALSE))
		{
			if (i < 0 || (identifier.has_flag
					&& identifier.flag.has_blank_on_positive && i > 0))
				count += print_space((size - psize) - 1);
			else if (identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0
				&& i == 0)
				count += print_space(size);
			else
				count += print_space(size - psize);
		}
		else
		{
			if (i < 0 || (identifier.has_flag
					&& identifier.flag.has_blank_on_positive && i > 0))
				count += print_space(size - ft_custom_nbrlen(i, FALSE) - 1);
			else if (identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0
				&& i == 0)
				count += print_space(size);
			else
				count += print_space(size - ft_custom_nbrlen(i, FALSE));
		}
	}
	else
	{
		if (identifier.has_flag && identifier.flag.has_zero_filler
			&& !(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width))
		{
			if (i < 0)
				count += print_char('-');
			if (identifier.has_flag
				&& identifier.flag.has_force_positive && i >= 0)
			{
				count += print_char('+');
				size--;
			}
			if (psize > ft_custom_nbrlen(i, TRUE))
				count += print_zero(size - psize);
			else
				count += print_zero(size - ft_custom_nbrlen(i, TRUE));
		}
		else
		{
			if (psize > ft_custom_nbrlen(i, FALSE))
			{
				if (i < 0 || (identifier.has_flag
						&& identifier.flag.has_force_positive && i > 0))
					count += print_space((size - psize) - 1);
				else if (identifier.has_print_settings
					&& identifier.print_settings.has_precision_width
					&& identifier.print_settings.precision_width == 0
					&& i == 0)
					count += print_space(size);
				else
					count += print_space(size - psize);
			}
			else
			{
				if (i < 0 || (identifier.has_flag
						&& identifier.flag.has_force_positive && i > 0))
					count += print_space(size - ft_custom_nbrlen(i, FALSE) - 1);
				else if (identifier.has_print_settings
					&& identifier.print_settings.has_precision_width
					&& identifier.print_settings.precision_width == 0
					&& i == 0)
					count += print_space(size);
				else
					count += print_space(size - ft_custom_nbrlen(i, FALSE));
			}
			if (i < 0)
				count += print_char('-');
			if (identifier.has_flag
				&& identifier.flag.has_force_positive && i >= 0)
			{
				count += print_char('+');
				size--;
			}
		}
		count += print_zero(psize - ft_custom_nbrlen(i, FALSE));
		if (!(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0)
			|| i != 0)
			count += print_string(number);
	}
	free(number);
	return (count);
}
