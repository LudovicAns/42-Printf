#include "ft_printf.h"
#include "process_utils.h"

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

	size = 1;
	c = va_arg(args, int);
	if (identifier.has_print_settings
		&& identifier.print_settings.has_min_field_width
		&& identifier.print_settings.min_field_width != 0)
		size = identifier.print_settings.min_field_width;
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
