/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:59:25 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:59:26 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "x_process.h"

/*
 * Function: ft_custom_nbrlen					1/5
 * ----------------------------------------
 *   Count lenght of a number.
 *
 *   nb: number to count
 *
 *   returns: lenght of the number.
 */
unsigned int	ft_custom_nbrlen_x(unsigned int nb)
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
char	*ft_custom_itoa_x(unsigned int nb)
{
	unsigned int	nui;
	char			*out;
	unsigned int	i;
	char			*base;

	base = "0123456789abcdef";
	out = (char *)malloc(sizeof(char) * (ft_custom_nbrlen_x(nb) + 1));
	if (!out)
		return (NULL);
	i = 0;
	nui = nb;
	i = ft_custom_nbrlen_x(nb) - 1;
	while (nui)
	{
		out[i--] = base[(nui % 16)];
		nui /= 16;
	}
	if (nb == 0)
		out[i] = base[0];
	out[ft_custom_nbrlen_x(nb)] = '\0';
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
int	get_print_size_x(t_identifier identifier, unsigned int nb)
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
		size = ft_custom_nbrlen_x(nb);
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
int	get_precision_size_x(t_identifier identifier)
{
	int	psize;

	psize = 0;
	if (identifier.has_print_settings
		&& identifier.print_settings.has_precision_width
		&& identifier.print_settings.precision_width >= 0)
		psize = identifier.print_settings.precision_width;
	return (psize);
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
 *   returns: number of printed chars.
 */
int	process_x(t_identifier identifier, va_list args)
{
	char			*number;
	unsigned int	i[4];
	int				(*complete)(int);

	i[0] = va_arg(args, unsigned int);
	i[1] = get_print_size_x(identifier, i[0]);
	i[2] = get_precision_size_x(identifier);
	i[3] = 0;
	number = ft_custom_itoa_x(i[0]);
	complete = get_funcomplete_x(identifier);
	if (identifier.flag.has_blank_on_positive)
		i[3] += print_space(1);
	if (identifier.has_flag && identifier.flag.has_left_justify)
		i[3] = left_justify_x(identifier, complete, number, i[3], i[0]);
	else
	{
		i[3] = process_spaces_x(identifier, complete, i[3], i[0]);
		i[3] = process_number_x(identifier, complete, number, i[3], i[0]);
	}
	free(number);
	return (i[3]);
}
