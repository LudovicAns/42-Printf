#include "ft_printf.h"

/*
 * Function: process_percentage					1/5
 * ----------------------------------------
 *   Process identifier using percentage argument type.
 *
 *   identifier: identifier
 *   args: arguments list
 *
 *   returns: number of printed chars.
 */
int	process_percentage(void)
{
	print_char('%');
	return (1);
}
