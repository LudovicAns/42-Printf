#include "ft_printf_utils.h"

/*
 * Function: is_format_identifier				1/5
 * ----------------------------------------
 *   Check if char is a format identifier.
 *
 *   c: tested char
 *
 *   returns: TRUE if c is a format identifier else FALSE.
 */
t_boolean	is_format_identifier(char c)
{
	t_boolean	state;

	if (c == '%')
		state = TRUE;
	else
		state = FALSE;
	return (state);
}

/*
 * Function: get_identifier						2/5
 * ----------------------------------------
 *   Get identifier at start_address.
 *
 *   start_address: string starting with format identifier
 *   args: arguments list
 *
 *   returns: t_identifier if he is valid or NULL if not.
 */
t_identifier	get_identifier(char *start_address, va_list args)
{
	t_flag				flag;
	t_print_settings	print_settings;
	t_argument_type		argument_type;

	start_address++;
	flag = get_flag(start_address);
	// get print settings [optional]
	// get argument type [required]
	// return identifier builded or NULL if argument type is invalid
}
