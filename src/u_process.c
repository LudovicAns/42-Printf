/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:58:39 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:58:40 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "u_process.h"
#include "ft_printf.h"

/*
 * Function: ft_nbrlen					1/5
 * ----------------------------------------
 *   Count lenght of a number with (or not) negative sign.
 *
 *   nb: number to count
 *   take_neg: negative count mode
 *
 *   returns: lenght of the number depending of take_neg.
 */
unsigned int	ft_custom_nbrlen_u(unsigned int nb)
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
char	*ft_custom_itoa_u(unsigned int nb)
{
	unsigned int	nui;
	char			*out;
	int				i;

	out = (char *)malloc(sizeof(char) * (ft_custom_nbrlen_u(nb) + 1));
	if (!out)
		return (NULL);
	i = 0;
	nui = nb;
	i = ft_custom_nbrlen_u(nb) - 1;
	while (nui)
	{
		out[i--] = (nui % 10) + '0';
		nui /= 10;
	}
	if (nb == 0)
		out[i] = '0';
	out[ft_custom_nbrlen_u(nb)] = '\0';
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
int	get_print_size_u(t_identifier identifier, int nb)
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
		size = ft_custom_nbrlen_u(nb);
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
int	get_precision_size_u(t_identifier identifier)
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
int	process_u(t_identifier identifier, va_list args)
{
	char			*number;
	unsigned int	i[4];
	int				(*complete)(int);

	i[0] = va_arg(args, unsigned int);
	i[1] = get_print_size_u(identifier, i[0]);
	i[2] = get_precision_size_u(identifier);
	i[3] = 0;
	number = ft_custom_itoa_u(i[0]);
	complete = get_funcomplete_u(identifier);
	if (identifier.flag.has_blank_on_positive)
		i[3] += print_space(1);
	if (identifier.has_flag && identifier.flag.has_left_justify)
		i[3] = left_justify_u(identifier, complete, number, i[3], i[0]);
	else
	{
		i[3] = process_spaces_u(identifier, complete, i[3], i[0]);
		i[3] = process_number_u(identifier, complete, number, i[3], i[0]);
	}
	free(number);
	return (i[3]);
}
