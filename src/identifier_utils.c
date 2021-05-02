#include "identifier.h"
#include <stdarg.h>

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

static t_identifier	get_identifier_fill(t_identifier identifier)
{
	t_flag				flag;
	t_print_settings	print_settings;

	flag = identifier.flag;
	print_settings = identifier.print_settings;
	if (flag.has_blank_on_positive || flag.has_force_positive
		|| flag.has_left_justify || flag.has_sharp || flag.has_zero_filler)
		identifier.has_flag = TRUE;
	else
		identifier.has_flag = FALSE;
	if (print_settings.has_min_field_width
		|| print_settings.has_precision_width)
		identifier.has_print_settings = TRUE;
	else
		identifier.has_print_settings = FALSE;
	if (identifier.has_print_settings
		&& identifier.print_settings.has_min_field_width
		&& identifier.print_settings.min_field_width < 0)
	{
		identifier.print_settings.min_field_width *= -1;
		identifier.has_flag = TRUE;
		identifier.flag.has_left_justify = TRUE;
	}
	return (identifier);
}

/*
 * Function: get_identifier						2/5
 * ----------------------------------------
 *   Get identifier at start_address.
 *
 *   start_address: string starting with format identifier
 *   args: arguments list
 *
 *   returns: builded t_identifier.
 */
t_identifier	get_identifier(char *start_address, va_list args)
{
	t_identifier		identifier;
	t_flag				flag;
	t_print_settings	print_settings;
	t_argument_type		argument_type;

	start_address++;
	flag = get_flag(start_address);
	identifier.flag = flag;
	start_address = skip_flags(start_address);
	print_settings = get_print_settings(start_address, args);
	identifier.print_settings = print_settings;
	start_address = skip_print_settings(start_address);
	argument_type = get_argument_type(*start_address);
	identifier.argument_type = argument_type;
	identifier = get_identifier_fill(identifier);
	return (identifier);
}

/*
 * Function: skip_identifier					3/5
 * ----------------------------------------
 *   Skip all chars corresponding to an identifier.
 *
 *   start_address: string starting after format identifier
 *   end: represent where we stop skipping
 *
 *   returns: start address with skipped identifier.
 */
char	*skip_identifier(char *start_address, char end)
{
	while (*start_address != end)
		start_address++;
	start_address++;
	return (start_address);
}
