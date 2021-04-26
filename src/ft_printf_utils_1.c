#include "ft_printf.h"

/*
 * Function: is_numeric							1/5
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

/*
 * Function: print_char							2/5
 * ----------------------------------------
 *   Print in stdout a char.
 *
 *   c: printed char
 *
 *   returns: 1
 */
int	print_char(char c)
{
	write(0, &c, 1);
	return (1);
}

/*
 * Function: launch_associated_process			3/5
 * ----------------------------------------
 *   Launch associated process to the identifier to print the result.
 *
 *   identifier: identifier
 *   args: arguments list
 *
 *   returns: number of printed chars
 */
int	launch_associated_process(t_identifier identifier, va_list args)
{
	char	argument_type;
	int		printed_chars;

	args = args;
	argument_type = identifier.argument_type.argument_type_char;
	if (argument_type == c)
		printed_chars = process_c(identifier, args);
	else if (argument_type == s)
		printed_chars = 0;
	else if (argument_type == p)
		printed_chars = process_p(identifier,  args);
	else if (argument_type == d)
		printed_chars = process_d(identifier, args);
	else if (argument_type == i)
		printed_chars = process_i(identifier, args);
	else if (argument_type == u)
		printed_chars = 0;
	else if (argument_type == x)
		printed_chars = 0;
	else if (argument_type == X)
		printed_chars = 0;
	else
		printed_chars = 0;
	return (printed_chars);
}
