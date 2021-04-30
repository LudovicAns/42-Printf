/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:25:18 by lanselin          #+#    #+#             */
/*   Updated: 2021/04/30 08:25:19 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_identifier	identifier;
	char			argument_type;
	int				count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (is_format_identifier(*format))
		{
			identifier = get_identifier((char *)format, args);
			if (identifier.argument_type.is_valid)
			{
				argument_type = identifier.argument_type.argument_type_char;
				count += launch_associated_process(identifier, args);
				format++;
				format = skip_identifier((char *)format, argument_type);
				continue ;
			}
		}
		print_char(*format++);
		count++;
	}
	va_end(args);
	return (count);
}
