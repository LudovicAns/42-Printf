/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:23:14 by lanselin          #+#    #+#             */
/*   Updated: 2021/04/30 08:23:15 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "d_process.h"
#include "ft_printf.h"

/*
 * Function: ft_custom_nbrlen_d					1/5
 * ----------------------------------------
 *   Count lenght of a number with (or not) negative sign.
 *
 *   nb: number to count
 *   take_neg: negative count mode
 *
 *   returns: lenght of the number depending of take_neg.
 */
int	ft_custom_nbrlen_d(int nb, t_boolean take_neg)
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
char	*ft_custom_itoa_d(int nb)
{
	unsigned int	nui;
	char			*out;
	int				i;

	out = (char *)malloc(sizeof(char) * (ft_custom_nbrlen_d(nb, FALSE) + 1));
	if (!out)
		return (NULL);
	i = 0;
	if (nb < 0)
		nui = -nb;
	else
		nui = nb;
	i = ft_custom_nbrlen_d(nb, FALSE) - 1;
	while (nui)
	{
		out[i--] = (nui % 10) + '0';
		nui /= 10;
	}
	if (nb == 0)
		out[i] = '0';
	out[ft_custom_nbrlen_d(nb, FALSE)] = '\0';
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
int	get_print_size_d(t_identifier identifier, int nb)
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
		size = ft_custom_nbrlen_d(nb, TRUE);
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
int	get_precision_size_d(t_identifier identifier)
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
	int		i[3];
	int		(*complete)(int);
	int		count;

	i[0] = va_arg(args, int);
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	number = ft_custom_itoa_d(i[0]);
	count = 0;
	complete = get_funcomplete_d(identifier);
	if (i[0] < 0 && complete == print_zero)
		count += print_char('-');
	if (i[0] >= 0 && identifier.flag.has_blank_on_positive)
		count += print_space(1);
	if (identifier.has_flag && identifier.flag.has_left_justify)
		count = left_justify_d(complete, identifier, count, i[0]);
	else
	{
		count = process_space_d(complete, identifier, count, i[0]);
		count = process_sign_d(complete, identifier, count, i[0]);
		count += print_zero(i[2] - ft_custom_nbrlen_d(i[0], FALSE));
		count = process_number_d(identifier, count, i[0]);
	}
	free(number);
	return (count);
}
