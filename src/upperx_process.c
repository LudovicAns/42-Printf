#include "ft_printf.h"

/*
 * Function: ft_custom_nbrlen					1/5
 * ----------------------------------------
 *   Count lenght of a number.
 *
 *   nb: number to count
 *
 *   returns: lenght of the number.
 */
static int	ft_custom_nbrlen(unsigned int nb)
{
	unsigned int	nui;
	unsigned int	i;

	i = 0;
	if (nb == 0)
		return (1);
	else
		nui = nb;
	while (nui)
	{
		nui /= 16;
		i++;
	}
	return (i);
}

/*
 * Function: ft_custom_itoa						2/5
 * ----------------------------------------
 *   Convert unsigned integer to string.
 *
 *   nb: number to convert
 *
 *   returns: string
 */
static char	*ft_custom_itoa(unsigned int nb)
{
	unsigned int	nui;
	char			*out;
	unsigned int	i;
	char			*base;

	base = "0123456789ABCDEF";
	out = (char *)malloc(sizeof(char) * (ft_custom_nbrlen(nb) + 1));
	if (!out)
		return (NULL);
	i = 0;
	nui = nb;
	i = ft_custom_nbrlen(nb) - 1;
	while (nui)
	{
		out[i--] = base[(nui % 16)];
		nui /= 16;
	}
	if (nb == 0)
		out[i] = base[0];
	out[ft_custom_nbrlen(nb)] = '\0';
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
static int	get_print_size(t_identifier identifier, unsigned int nb)
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
		size = ft_custom_nbrlen(nb);
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
 * Function: process_X							5/5
 * ----------------------------------------
 *   Process identifier using X argument type.
 *
 *   identifier: identifier
 *   args = arguments list
 *
 *   returns: number of printed chars.
 */
int	process_X(t_identifier identifier, va_list args)
{
	char				*number;
	unsigned int		i;
	int					size;
	int					psize;
	int					count;

	i = va_arg(args, unsigned int);
	number = ft_custom_itoa(i);
	size = get_print_size(identifier, i);
	psize = get_precision_size(identifier);
	count = 0;
	if (identifier.has_flag && identifier.flag.has_left_justify)
	{
		if (identifier.has_flag && identifier.flag.has_sharp && i != 0)
			count += print_string("0X");
		count += print_zero(psize - ft_custom_nbrlen(i));
		if (!(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0)
			|| i != 0)
			count += print_string(number);
		if (psize > ft_custom_nbrlen(i))
		{
			if (identifier.has_flag
				&& identifier.flag.has_sharp && i != 0)
				count += print_space((size - psize) - 2);
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
			if (identifier.has_flag
				&& identifier.flag.has_blank_on_positive)
				count += print_space(size - ft_custom_nbrlen(i) - 1);
			else if (identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0
				&& i == 0)
				count += print_space(size);
			else if (identifier.flag.has_sharp && i != 0)
			{
				if (psize > ft_custom_nbrlen(i) + 2)
					count += print_zero(size - psize);
				else
					count += print_zero(size - (ft_custom_nbrlen(i) + 2));
			}
			else
				count += print_space(size - ft_custom_nbrlen(i));
		}
	}
	else
	{
		if (identifier.has_flag && identifier.flag.has_zero_filler
			&& !(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width))
		{
			if (identifier.flag.has_sharp && i != 0)
			{
				if (psize > ft_custom_nbrlen(i) + 2)
					count += print_zero(size - psize);
				else
					count += print_zero(size - (ft_custom_nbrlen(i) + 2));
			}
			else
			{
				if (psize > ft_custom_nbrlen(i))
					count += print_zero(size - psize);
				else
					count += print_zero(size - ft_custom_nbrlen(i));
			}
		}
		else
		{
			if (psize > ft_custom_nbrlen(i))
			{
				if (identifier.has_flag
					&& identifier.flag.has_sharp && i != 0)
					count += print_space((size - psize) - 2);
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
				if (identifier.has_flag
					&& identifier.flag.has_sharp && i != 0)
					count += print_space(size - ft_custom_nbrlen(i) - 2);
				else if (identifier.has_print_settings
					&& identifier.print_settings.has_precision_width
					&& identifier.print_settings.precision_width == 0
					&& i == 0)
					count += print_space(size);
				else
					count += print_space(size - ft_custom_nbrlen(i));
			}
		}
		if (identifier.has_flag && identifier.flag.has_sharp && i != 0)
			count += print_string("0X");
		count += print_zero(psize - ft_custom_nbrlen(i));
		if (!(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0)
			|| i != 0)
			count += print_string(number);
	}
	free(number);
	return (count);
}
