/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:24:48 by lanselin          #+#    #+#             */
/*   Updated: 2021/04/30 08:24:50 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
static unsigned int	ft_custom_nbrlen(unsigned int nb)
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

	base = "0123456789abcdef";
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
		&& identifier.print_settings.has_precision_width
		&& identifier.print_settings.precision_width >= 0)
		psize = identifier.print_settings.precision_width;
	return (psize);
}

static void	*get_funcomplete(t_identifier identifier)
{
	if (identifier.has_flag && identifier.flag.has_zero_filler)
	{
		if (identifier.flag.has_left_justify)
			return (print_space);
		else if (identifier.has_print_settings
			&& identifier.print_settings.has_precision_width
			&& identifier.print_settings.precision_width >= 0)
			return (print_space);
		else
			return (print_zero);
	}
	return (print_space);
}

/*
 * Function: process_u							5/5
 * ----------------------------------------
 *   Process identifier using u argument type.
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
int	process_x(t_identifier identifier, va_list args)
{
	char			*number;
	unsigned int	i[4];
	int				(*complete)(int);

	i[0] = va_arg(args, unsigned int);
	i[1] = get_print_size(identifier, i[0]);
	i[2] = get_precision_size(identifier);
	i[3] = 0;
	number = ft_custom_itoa(i[0]);
	complete = get_funcomplete(identifier);
	if (identifier.flag.has_blank_on_positive)
		i[3] += print_space(1);
	if (identifier.has_flag && identifier.flag.has_left_justify)
	{
		if (identifier.flag.has_force_positive)
			i[3] += print_char('+');
		if (identifier.flag.has_sharp && i[0] != 0)
			i[3] += print_string("0x");
		i[3] += print_zero(i[2] - ft_custom_nbrlen(i[0]));
		if (!(identifier.has_print_settings
				&& identifier.print_settings.has_precision_width
				&& identifier.print_settings.precision_width == 0 && i[0] == 0))
			i[3] += print_string(number);
		if (i[3] < i[1])
			i[3] += complete(i[1] - i[3]);
	}
	else
	{
		if (ft_custom_nbrlen(i[0]) < i[1] && i[1] > i[2])
		{
			if (i[2] < ft_custom_nbrlen(i[0]))
			{
				if (identifier.flag.has_force_positive && i[3] == 0)
					i[3] += complete((i[1] - i[3])
							- ft_abs(i[2] - ft_custom_nbrlen(i[0])) - i[2] - 1);
				else if (identifier.flag.has_sharp && i[0] != 0)
					i[3] += complete((i[1] - i[3])
							- ft_abs(i[2] - ft_custom_nbrlen(i[0])) - i[2] - 2);
				else
					i[3] += complete((i[1] - i[3])
							- ft_abs(i[2] - ft_custom_nbrlen(i[0])) - i[2]);
			}
			else
			{
				if (identifier.flag.has_force_positive && i[3] == 0)
					i[3] += complete((i[1] - i[3]) - i[2] - 1);
				else if (identifier.flag.has_sharp && i[0] != 0)
					i[3] += complete((i[1] - i[3]) - i[2] - 2);
				else
					i[3] += complete((i[1] - i[3]) - i[2]);
			}
		}
		if (identifier.flag.has_force_positive)
			i[3] += print_char('+');
		if (identifier.flag.has_sharp && i[0] != 0)
			i[3] += print_string("0x");
		i[3] += print_zero(i[2] - ft_custom_nbrlen(i[0]));
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
