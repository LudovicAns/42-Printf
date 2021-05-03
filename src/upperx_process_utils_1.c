/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upperx_process_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:59:18 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:59:19 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "upperx_process.h"
#include "process_utils.h"

unsigned int	process_number_X(t_identifier identifier, int (*complete)(int),
	char *number, unsigned int count, unsigned int nb)
{
	unsigned int	i[3];

	i[0] = nb;
	i[1] = get_print_size_X(identifier, i[0]);
	i[2] = get_precision_size_X(identifier);
	if (identifier.flag.has_force_positive)
		count += print_char('+');
	if (identifier.flag.has_sharp && i[0] != 0)
		count += print_string("0X");
	count += print_zero(i[2] - ft_custom_nbrlen_X(i[0]));
	if (!(identifier.has_print_settings
			&& identifier.print_settings.has_precision_width
			&& identifier.print_settings.precision_width == 0 && i[0] == 0))
		count += print_string(number);
	else
		count += complete(i[1] - count);
	return (count);
}

static unsigned int	process_spaces2_X(t_identifier identifier,
	int (*complete)(int), unsigned int count, unsigned int nb)
{
	unsigned int	i[3];

	i[0] = nb;
	i[1] = get_print_size_X(identifier, i[0]);
	i[2] = get_precision_size_X(identifier);
	if (identifier.flag.has_force_positive && count == 0)
		count += complete((i[1] - count)
				- ft_abs(i[2] - ft_custom_nbrlen_X(i[0])) - i[2] - 1);
	else if (identifier.flag.has_sharp && i[0] != 0)
		count += complete((i[1] - count)
				- ft_abs(i[2] - ft_custom_nbrlen_X(i[0])) - i[2] - 2);
	else
		count += complete((i[1] - count)
				- ft_abs(i[2] - ft_custom_nbrlen_X(i[0])) - i[2]);
	return (count);
}

unsigned int	process_spaces_X(t_identifier identifier, int (*complete)(int),
	unsigned int count, unsigned int nb)
{
	unsigned int	i[3];

	i[0] = nb;
	i[1] = get_print_size_X(identifier, i[0]);
	i[2] = get_precision_size_X(identifier);
	if (ft_custom_nbrlen_X(i[0]) < i[1] && i[1] > i[2])
	{
		if (i[2] < ft_custom_nbrlen_X(i[0]))
			count = process_spaces2_X(identifier, complete, count, nb);
		else
		{
			if (identifier.flag.has_force_positive && count == 0)
				count += complete((i[1] - count) - i[2] - 1);
			else if (identifier.flag.has_sharp && i[0] != 0)
				count += complete((i[1] - count) - i[2] - 2);
			else
				count += complete((i[1] - count) - i[2]);
		}
	}
	return (count);
}

unsigned int	left_justify_X(t_identifier identifier, int (*complete)(int),
	char *number, unsigned int count, unsigned int nb)
{
	unsigned int	i[3];

	i[0] = nb;
	i[1] = get_print_size_X(identifier, i[0]);
	i[2] = get_precision_size_X(identifier);
	if (identifier.flag.has_force_positive)
		count += print_char('+');
	if (identifier.flag.has_sharp && i[0] != 0)
		count += print_string("0X");
	count += print_zero(i[2] - ft_custom_nbrlen_X(i[0]));
	if (!(identifier.has_print_settings
			&& identifier.print_settings.has_precision_width
			&& identifier.print_settings.precision_width == 0 && i[0] == 0))
		count += print_string(number);
	if (count < i[1])
		count += complete(i[1] - count);
	return (count);
}

void	*get_funcomplete_X(t_identifier identifier)
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
