#include "flag.h"

/*
 * Function: is_flag_type						1/5
 * ----------------------------------------
 *   Check if char is a flag.
 *
 *   c: tested char
 *
 *   returns: TRUE if c is a flag else FALSE.
 */
t_boolean	is_flag_type(char c)
{
	if (c == LEFT_JUSTIFY || c == ZERO_FILLER
		|| c == FORCE_POSITIVE || c == BLANK_ON_POSITIVE
		|| c == SHARP)
		return (TRUE);
	return (FALSE);
}

/*
 * Function: get_flag_type						2/5
 * ----------------------------------------
 *   Convert char to t_flag_type.
 *
 *   c: converted char
 *
 *   returns: t_flag_type of char c.
 */
t_flag_type	get_flag_type(char c)
{
	if (c == LEFT_JUSTIFY)
		return (LEFT_JUSTIFY);
	else if (c == ZERO_FILLER)
		return (ZERO_FILLER);
	else if (c == FORCE_POSITIVE)
		return (FORCE_POSITIVE);
	else if (c == BLANK_ON_POSITIVE)
		return (BLANK_ON_POSITIVE);
	else
		return (SHARP);
}

/*
 * Function: set_flag_type						3/5
 * ----------------------------------------
 *   Change value of one flag type in a flag.
 *
 *   flag_type: affected flag type
 *   bool: value to set in flag type
 *   flag: affected flag
 *
 *   returns: modified t_flag
 */
void	set_flag_type(t_flag_type flag_type, t_boolean bool, t_flag *flag)
{
	if (flag_type == LEFT_JUSTIFY)
		flag->has_left_justify = bool;
	else if (flag_type == ZERO_FILLER)
		flag->has_zero_filler = bool;
	else if (flag_type == FORCE_POSITIVE)
		flag->has_force_positive = bool;
	else if (flag_type == BLANK_ON_POSITIVE)
		flag->has_blank_on_positive = bool;
	else if (flag_type == SHARP)
		flag->has_sharp = bool;
}

/*
 * Function: get_flag							4/5
 * ----------------------------------------
 *   Get flag at start address.
 *
 *   start_address: string starting after format identifier
 *
 *   returns: t_flag at start address.
 */
t_flag	get_flag(char *start_address)
{
	t_flag		flag;

	flag.has_blank_on_positive = FALSE;
	flag.has_force_positive = FALSE;
	flag.has_left_justify = FALSE;
	flag.has_sharp = FALSE;
	flag.has_zero_filler = FALSE;
	while (is_flag_type(*start_address))
	{
		set_flag_type(get_flag_type(*start_address), TRUE, &flag);
		start_address++;
	}
	return (flag);
}

/*
 * Function: skip_flags							5/5
 * ----------------------------------------
 *   Skip all chars corresponding to a flag type.
 *
 *   start_address: string starting after format identifier
 *
 *   returns: start address with skipped flag type.
 */
char	*skip_flags(char *start_address)
{
	while (is_flag_type(*start_address))
		start_address++;
	return (start_address);
}
