#include "flag.h"
#include "unistd.h"

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
 *   returns: t_flag_type if c is a valid flag type else NULL.
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
	else if (c == SHARP)
		return (SHARP);
	else
		return (NULL);
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
 *   returns: nothing
 */
void	set_flag_type(t_flag_type flag_type, t_boolean bool, t_flag flag)
{
	if (flag_type == LEFT_JUSTIFY)
		flag.has_left_justify = bool;
	else if (flag_type == ZERO_FILLER)
		flag.has_zero_filler = bool;
	else if (flag_type == FORCE_POSITIVE)
		flag.has_force_positive = bool;
	else if (flag_type == BLANK_ON_POSITIVE)
		flag.has_blank_on_positive = bool;
	else if (flag_type == SHARP)
		flag.has_sharp = bool;
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
	t_boolean	has_flag;

	has_flag = FALSE;
	while (is_flag_type(*start_address))
	{
		has_flag = TRUE;
		set_flag_type(get_flag_type(*start_address), TRUE, flag);
		start_address++;
	}
	return (flag);
}
