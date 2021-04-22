#include "argument_type.h"

/*
 * Function: get_argument_type	        		1/5
 * ----------------------------------------
 *   Build t_argument_type from a char.
 *
 *   c: converted char
 *
 *   returns: builded t_argument_type.
 */
t_argument_type	get_argument_type(char c)
{
	t_argument_type	argument_type;

	if (is_valid_argument_type_char(c))
	{
		argument_type.is_valid = TRUE;
		argument_type.argument_type_char = get_argument_type_char(c);
	}
	else
		argument_type.is_valid = FALSE;
	return (argument_type);
}

/*
 * Function: is_valid_argument_type_char		2/5
 * ----------------------------------------
 *   Check if char is a valid argument type char.
 *
 *   ch: tested char
 *
 *   returns: TRUE if he is valid else FALSE.
 */
static t_boolean	is_valid_argument_type_char(char ch)
{
	if (ch == c || ch == s || ch == p || ch == d || ch == i || ch == u
		|| ch == x || ch == x || ch == X || ch == percentage)
		return (TRUE);
	else
		return (FALSE);
}

/*
 * Function: get_argument_type_char	       		3/5
 * ----------------------------------------
 *   Convert char to t_argument_type_char.
 *
 *   ch: converted char
 *
 *   returns: converted t_argument_type_char.
 */
static t_argument_type_char	get_argument_type_char(char ch)
{
	if (ch == c)
		return (c);
	else if (ch == s)
		return (s);
	else if (ch == p)
		return (p);
	else if (ch == d)
		return (d);
	else if (ch == i)
		return (i);
	else if (ch == u)
		return (u);
	else if (ch == x)
		return (x);
	else if (ch == X)
		return (X);
	else
		return (percentage);
}
