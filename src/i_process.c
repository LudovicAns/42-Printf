/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:23:47 by lanselin          #+#    #+#             */
/*   Updated: 2021/04/30 08:23:49 by lanselin         ###   ########lyon.fr   */
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
