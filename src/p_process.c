/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:25:37 by lanselin          #+#    #+#             */
/*   Updated: 2021/04/30 08:25:38 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function: print_pointer						1/5
 * ----------------------------------------
 *   Count lenght of number in hexa base.
 *
 *   nb: number
 *
 *   returns: lenght of a number in hexa base.
 */
static int	ft_nbhex_len(unsigned long int nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

/*
 * Function: print_pointer						2/5
 * ----------------------------------------
 *   Print pointer
 *
 *   nb: number
 *
 *   returns: number of printed chars.
 */
int	print_pointer(unsigned long int nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nb > 15)
	{
		count += print_pointer(nb / 16);
		count += print_pointer(nb % 16);
	}
	if (nb < 16)
		count += print_char(base[nb]);
	return (count);
}

/*
 * Function: get_size							3/5
 * ----------------------------------------
 *   Return size of printed pointer.
 *
 *   identifier: identifier
 *   nb: number
 *
 *   returns: number of printed chars.
 */
static int	get_size(t_identifier identifier, unsigned long int nb)
{
	int	size;

	size = 1;
	if (identifier.has_print_settings
		&& identifier.print_settings.has_min_field_width)
		size = identifier.print_settings.min_field_width;
	else
		size = ft_nbhex_len(nb) + 2;
	if (size < ft_nbhex_len(nb) + 2)
		size = ft_nbhex_len(nb) + 2;
	return (size);
}

/*
 * Function: process_p							5/5
 * ----------------------------------------
 *   Process identifier using p argument type.
 *
 *   identifier: identifier
 *   args: arguments list
 *
 *   returns: number of printed chars.
 */
int	process_p(t_identifier identifier, va_list args)
{
	unsigned long int	nb;
	int					size;
	int					count;

	nb = va_arg(args, unsigned long int);
	size = get_size(identifier, nb);
	count = 0;
	//if (nb == 0)
	//	return (print_null_pointer(identifier, size));
	if (identifier.has_flag && identifier.flag.has_left_justify)
	{
		count += print_string("0x");
		count += print_pointer(nb);
		count += print_space(size - count);
	}
	else
	{
		count += print_space(size - (ft_nbhex_len(nb) + 2));
		count += print_string("0x");
		count += print_pointer(nb);
	}
	return (count);
}
