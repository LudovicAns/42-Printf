/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:25:04 by lanselin          #+#    #+#             */
/*   Updated: 2021/04/30 08:25:06 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process_utils.h"

/*
 * Function: get_print_size						1/5
 * ----------------------------------------
 *   Return size of print.
 *
 *   identifier: identifier
 *
 *   returns: size of print.
 */
static int	get_print_size(t_identifier identifier)
{
	int	size;

	size = 1;
	if (identifier.has_print_settings
		&& identifier.print_settings.has_min_field_width
		&& identifier.print_settings.min_field_width != 0)
		size = identifier.print_settings.min_field_width;
	return (size);
}

/*
 * Function: process_c							2/5
 * ----------------------------------------
 *   Process identifier using c argument type.
 *
 *   identifier: identifier
 *   args: arguments list
 *
 *   returns: number of printed chars.
 */
int	process_c(t_identifier identifier, va_list args)
{
	int		size;
	char	c;

	size = get_print_size(identifier);
	c = va_arg(args, int);
	if (size < 0)
	{
		size *= -1;
		identifier.has_flag = TRUE;
		identifier.flag.has_left_justify = TRUE;
	}
	if (identifier.has_flag && identifier.flag.has_left_justify)
	{
		print_char(c);
		print_space(size - 1);
	}
	else
	{
		print_space(size - 1);
		print_char(c);
	}
	return (size);
}
