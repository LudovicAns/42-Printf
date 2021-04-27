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
	write(1, &c, 1);
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

	argument_type = identifier.argument_type.argument_type_char;
	if (argument_type == c)
		printed_chars = process_c(identifier, args);
	else if (argument_type == s)
		printed_chars = process_s(identifier, args);
	else if (argument_type == p)
		printed_chars = process_p(identifier, args);
	else if (argument_type == d)
		printed_chars = process_d(identifier, args);
	else if (argument_type == i)
		printed_chars = process_i(identifier, args);
	else if (argument_type == u)
		printed_chars = process_u(identifier, args);
	else if (argument_type == x)
		printed_chars = process_x(identifier, args);
	else if (argument_type == X)
		printed_chars = process_X(identifier, args);
	else
		printed_chars = process_percentage();
	return (printed_chars);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		count;
	int		sign;

	if (!nptr)
		return (0);
	count = 0;
	sign = 1;
	while (ft_isspace(*nptr) && *nptr)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			sign = -1;
		else
			sign = 1;
	}
	while ((*nptr >= '0' && *nptr <= '9') && *nptr)
		count = count * 10 + (*nptr++ - 48);
	return (count * sign);
}
