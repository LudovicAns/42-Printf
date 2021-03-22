#include "ft_printf_utils.h"

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

t_boolean	is_print_configuration(const char *start_address)
{
	if (is_numeric(start_address[0]))
		return (TRUE);
	return (FALSE);
}

t_boolean	is_precision(const char *start_address)
{
	if (start_address[0] == '.')
		return (TRUE);
	return (FALSE);
}

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

void	printchar(char c)
{
	write(0, &c, 1);
}
