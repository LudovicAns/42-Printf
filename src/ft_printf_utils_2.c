#include "ft_printf_utils.h"

/*
 * Function: printstring				1/5
 * ----------------------------------------
 *   Display a string in stdout
 *
 *   *string: pointer of char 
 *
 *   returns: nothing
 */
void	printstring(char *string)
{
	while (*string)
	{
		printchar(*string);
		string++;
	}
}

/*
 * Function: is_numeric					2/5
 * ----------------------------------------
 *   Returns t_boolean depending of character value
 *
 *   c: tested character
 *
 *   returns: TRUE if c is numeric else FALSE
 */
t_boolean	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	return (FALSE);
}

/*
 * Function: is_specification			3/5
 * ----------------------------------------
 *   Returns t_boolean depending of character value
 *
 *   c: tested character
 *
 *   returns: TRUE if c is specification else FALSE
 */
t_boolean	is_specification(char c)
{
	if (c == '%')
		return (TRUE);
	return (FALSE);
}

/*
 * Function: get_specification_result	4/5
 * ----------------------------------------
 *   Returns the result (char *) of a specification
 *
 *   *specification: pointer of t_specification
 *
 *   returns: converted specification in (char *)
 */
char	*get_specification_result(t_specification *specification)
{
	specification = NULL;
	// Use t_specification and convert to (char *).
	return ("dd");
}

/*
 * Function: get_specification			5/5
 * ----------------------------------------
 *   Returns the square of the largest of its two input values
 *
 *   *start_address: pointer of (char *) where start the specification
 *   *args: th va_list who contain needed arg
 *
 *   returns: the t_specification created or NULL if it can't be created
 */
t_specification	get_specification(const char *start_address)
{
	char			*s;
	int				i;
	t_specification	specification;

	s = (char *)start_address;
	i = 1;
	if (is_print_configuration(&s[i]))
	{
		specification.has_print_configuration = TRUE;
		specification.print_configuration = get_print_configuration(&s[i]);
		while (is_numeric(s[i]) || s[i] == ' ')
			i++;
	}
	else
	{
		specification.has_print_configuration = FALSE;
		specification.print_configuration = NULL;
	}
	if (is_precision(&s[i]))
	{
		specification.has_precision = TRUE;
		specification.precision = get_precision(&s[i]);
		i++;
		while (is_numeric(s[i]) || s[i] == ' ')
			i++;
	}
	else
	{
		specification.has_precision = FALSE;
		specification.precision = NULL;
	}
	if (is_definer(&s[i]))
		specification.definer = s[i];
	else
	{
		specification.definer = '\0';
	}
	return (specification);
}
