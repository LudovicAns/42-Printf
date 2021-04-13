#include "ft_printf_utils.h"

/*
 * Function: get_numspecification				1/5
 * ----------------------------------------
 *   Get number of specification in format
 *
 *   *format: constant pointer of char 
 *
 *   returns: integer value of specification
 */
int	get_numspecification(const char *format)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[i + 1] == ' ')
				i++;
			c = format[i + 1];
			if (is_definer(&c) || is_precision(&c)
				|| is_print_configuration(&c))
			{
				count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

/*
 * Function: is_print_configuration				2/5
 * ----------------------------------------
 *   Check if first char in start_address is a print_configuration
 *
 *   *start_address: constant pointer of char 
 *
 *   returns: t_boolean set to TRUE if first char is a print_configuration
 *			  else FALSE
 */
t_boolean	is_print_configuration(const char *start_address)
{
	if (is_numeric(start_address[0]))
		return (TRUE);
	return (FALSE);
}

/*
 * Function: is_precision						3/5
 * ----------------------------------------
 *   Check if first char in start_address is a precision
 *
 *   *start_address: constant pointer of char 
 *
 *   returns: t_boolean set to TRUE if first char is a precision else FALSE
 */
t_boolean	is_precision(const char *start_address)
{
	if (start_address[0] == '.')
		return (TRUE);
	return (FALSE);
}

/*
 * Function: is_definer						4/5
 * ----------------------------------------
 *   Check if first char in start_address is a definer
 *
 *   *start_address: constant pointer of char 
 *
 *   returns: t_boolean set to TRUE if first char is a definer else FALSE
 */
t_boolean	is_definer(const char *start_address)
{
	char	definer;

	definer = start_address[0];
	if (definer == d || definer == i || definer == x || definer == big_X
		|| definer == c || definer == u || definer == p || definer == s
		|| definer == percentage)
		return (TRUE);
	return (FALSE);
}

/*
 * Function: printchar						5/5
 * ----------------------------------------
 *   Check if first char in start_address is a definer
 *
 *   *c: char to print
 *
 *   returns: nothing
 */
void	printchar(char c)
{
	write(0, &c, 1);
}
