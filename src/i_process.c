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