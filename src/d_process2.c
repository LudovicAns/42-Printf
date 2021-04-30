/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_process2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:32:46 by lanselin          #+#    #+#             */
/*   Updated: 2021/04/30 08:32:46 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "identifier.h"
#include "process_utils.h"
#include "d_process.h"

void	*get_funcomplete_d(t_identifier identifier)
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

int	left_justify_d(int (*complete)(int), t_identifier identifier, int count, int n)
{
	char	*number;
	int		i[3];

	i[0] = n;
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	number = ft_custom_itoa_d(i[0]);
	if (i[0] < 0 && !(complete == print_zero))
		count += print_char('-');
	if (i[0] >= 0 && identifier.flag.has_force_positive)
		count += print_char('+');
	count += print_zero(i[2] - ft_custom_nbrlen_d(i[0], FALSE));
	if (!(identifier.has_print_settings
			&& identifier.print_settings.has_precision_width
			&& identifier.print_settings.precision_width == 0 && i[0] == 0))
		count += print_string(number);
	else
		count += complete(i[1] - count);
	if (count < i[1])
		count += complete(i[1] - count);
	free(number);
	return (count);
}

int	process_sign_d(int (*complete)(int), t_identifier identifier, int count, int n)
{
	char	*number;
	int		i[3];

	i[0] = n;
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	number = ft_custom_itoa_d(i[0]);
	if (i[0] < 0 && !(complete == print_zero))
		count += print_char('-');
	if (i[0] >= 0 && identifier.flag.has_force_positive)
		count += print_char('+');
	free(number);
	return (count);
}

int	process_number_d(t_identifier identifier, int count, int n)
{
	char	*number;
	int		i[3];

	i[0] = n;
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	number = ft_custom_itoa_d(i[0]);
	count += print_zero(i[2] - ft_custom_nbrlen_d(i[0], FALSE));
	if (!(identifier.has_print_settings
			&& identifier.print_settings.has_precision_width
			&& identifier.print_settings.precision_width == 0 && i[0] == 0))
		count += print_string(number);
	else
		count += print_space(i[1] - count);
	free(number);
	return (count);
}

int	process_space_d(int (*complete)(int), t_identifier identifier,
	int count, int n)
{
	char	*number;
	int		i[3];

	i[0] = n;
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	number = ft_custom_itoa_d(i[0]);
	if (ft_custom_nbrlen_d(i[0], FALSE) < i[1] && i[1] > i[2])
	{
		if (i[2] < ft_custom_nbrlen_d(i[0], FALSE))
		{
			if ((i[0] < 0 || (i[0] >= 0
						&& identifier.flag.has_force_positive)) && count == 0)
				count += complete((i[1] - count)
						- ft_abs(i[2] - ft_custom_nbrlen_d(i[0], FALSE)
							- i[2]) - 1);
			else
				count += complete((i[1] - count)
						- ft_abs(i[2] - ft_custom_nbrlen_d(i[0], FALSE)
							- i[2]));
		}
		else
		{
			if ((i[0] < 0 || (i[0] >= 0
						&& identifier.flag.has_force_positive))
				&& count == 0)
				count += complete((i[1] - count) - i[2] - 1);
			else
				count += complete((i[1] - count) - i[2]);
		}
	}
	free(number);
	return (count);
}
