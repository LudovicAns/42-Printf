/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:56:34 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:56:35 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function: process_i							1/5
 * ----------------------------------------
 *   Process identifier using i argument type.
 *
 *   identifier: identifier
 *   args: arguments list
 *
 *   returns: number of printed chars.
 */
int	process_i(t_identifier identifier, va_list args)
{
	return (process_d(identifier, args));
}
