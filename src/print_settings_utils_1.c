/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_settings_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:57:41 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:57:42 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "print_settings.h"
#include "ft_printf.h"

/*
 * Function: get_numeric_size					1/5
 * ----------------------------------------
 *   Return number of numeric chars at start address.
 *
 *   start_address: string starting with numeric char
 *
 *   returns: number of numeric chars.
 */
static int	get_numeric_size(char *start_address)
{
	int	count;

	count = 0;
	while (is_numeric(*start_address))
	{
		count++;
		start_address++;
	}
	return (count);
}

/*
 * Function: get_numeric_string					2/5
 * ----------------------------------------
 *   Return malloced string of numeric chars at start address.
 *
 *   start_address: string starting with numeric char
 *
 *   returns: malloced string of numeric chars or NULL if can't malloc.
 */
char	*get_numeric_string(char *start_address)
{
	int		i;
	char	*string;

	i = get_numeric_size(start_address);
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (is_numeric(*start_address))
	{
		string[i++] = *start_address;
		start_address++;
	}
	string[i] = '\0';
	return (string);
}

/*
 * Function: is_print_settings					3/5
 * ----------------------------------------
 *   Check if char c is a print settings.
 *
 *   c: tested char
 *
 *   returns: TRUE if c is a print settings else FALSE.
 */
t_boolean	is_print_settings(char c)
{
	if (is_numeric(c) || c == '.' || c == '*')
		return (TRUE);
	return (FALSE);
}

/*
 * Function: get_print_settings					4/5
 * ----------------------------------------
 *   Return builded print settings from start address.
 *
 *   start_address: string starting with print settings char
 *   args: args list
 *
 *   returns: builded t_print_settings.
 */
t_print_settings	get_print_settings(char *start_address, va_list args)
{
	t_print_settings	print_settings;
	char				*num_string;

	print_settings = treat_field_width(start_address, args);
	while (is_numeric(*start_address) || *start_address == '*')
		start_address++;
	if (*start_address == '.')
	{
		print_settings.has_precision_width = TRUE;
		start_address++;
		if (is_numeric(*start_address))
		{
			num_string = get_numeric_string(start_address);
			print_settings.precision_width = ft_atoi(num_string);
			free(num_string);
			num_string = NULL;
		}
		else if (*start_address == '*')
			print_settings.precision_width = va_arg(args, int);
		else
			print_settings.precision_width = 0;
	}
	else
		print_settings.has_precision_width = FALSE;
	return (print_settings);
}

/*
 * Function: skip_print_settings					5/5
 * ----------------------------------------
 *   Skip all chars corresponding to a print_settings.
 *
 *   start_address: string starting with print settings char.
 *
 *   returns: start address with skipped print settings.
 */
char	*skip_print_settings(char *start_address)
{
	while (is_print_settings(*start_address))
		start_address++;
	return (start_address);
}
