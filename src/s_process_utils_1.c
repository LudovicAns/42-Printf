/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_process_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:58:33 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:58:34 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "s_process.h"
#include "printf.h"
#include "process_utils.h"

/*
 * Function: print_null_pointer						5/5
 * ----------------------------------------
 *   Print for null pointer.
 *
 *   identifier: identifier
 *   size: print size
 *
 *   returns: number of printed chars.
 */
int	print_null_pointer(int psize)
{
	return (custom_print_string_s("(null)", psize));
}

int	left_justify_s(char *string, int count, int size, int psize)
{
	if (string)
	{
		count += custom_print_string_s(string, psize);
		count += print_space(size - count);
	}
	else
	{
		count += print_null_pointer(psize);
		count += print_space(size - count);
	}
	return (count);
}
