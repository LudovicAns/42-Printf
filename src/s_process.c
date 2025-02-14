/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:58:17 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:58:18 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "s_process.h"
#include "ft_printf.h"

/*
 * Function: custom_print_string				1/5
 * ----------------------------------------
 *   Print 'max' first char in string.
 *
 *   string: string to print.
 *   max: max chars to print.
 *
 *   returns: number of printed chars.
 */
int	custom_print_string_s(char *string, int max)
{
	int	count;

	count = 0;
	while (*string && count != max)
	{
		print_char(*string);
		count++;
		string++;
	}
	return (count);
}

/*
 * Function: ft_strlen							2/5
 * ----------------------------------------
 *   Count number of char in a string.
 *
 *   string: string to count.
 * 
 *   returns: number of char in string.
 */
static int	ft_strlen(char *string)
{
	int	count;

	count = 0;
	if (!string)
		return (6);
	while (*string)
	{
		count++;
		string++;
	}
	return (count);
}

/*
 * Function: get_print_size						3/5
 * ----------------------------------------
 *   Return total print size depending on identifier.
 *
 *   identifier: identifier
 *   string: string
 * 
 *   returns: Total print size.
 */
static int	get_print_size(t_identifier identifier, char *string)
{
	int	size;

	if (identifier.has_print_settings)
	{
		if (identifier.print_settings.has_min_field_width)
			size = identifier.print_settings.min_field_width;
		else
		{
			if (ft_strlen(string) >= identifier.print_settings.precision_width)
				size = identifier.print_settings.precision_width;
			else
				size = ft_strlen(string);
		}
		return (size);
	}
	else
		return (ft_strlen(string));
}

static int	get_psize(t_identifier identifier, char *string)
{
	int	psize;

	psize = ft_strlen(string);
	if (identifier.has_print_settings
		&& identifier.print_settings.has_precision_width)
		return (identifier.print_settings.precision_width);
	return (psize);
}

/*
 * Function: process_s							6/5
 * ----------------------------------------
 *   Process identifier using s argument type.
 *
 *   identifier: identifier
 *   args: arguments list
 *
 *   returns: number of printed chars.
 */
int	process_s(t_identifier identifier, va_list args)
{
	char	*string;
	int		size;
	int		count;
	int		psize;

	count = 0;
	string = va_arg(args, char *);
	size = get_print_size(identifier, string);
	psize = get_psize(identifier, string);
	if (identifier.has_flag && identifier.flag.has_left_justify)
		count = left_justify_s(string, count, size, psize);
	else
	{
		if (psize < ft_strlen(string) && psize >= 0)
			count += print_space(size - psize);
		else
			count += print_space(size - ft_strlen(string));
		if (string)
			count += custom_print_string_s(string, psize);
		else
			count += print_null_pointer(psize);
	}
	return (count);
}
