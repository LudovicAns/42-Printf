#include "ft_printf_utils.h"

/*
 * Function: is_numeric							3/5
 * ----------------------------------------
 *   Check if char is numeric.
 *
 *   c: tested char
 *
 *   returns: TRUE if c is numeric else FALSE.
 */
t_boolean	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	return (FALSE);
}
