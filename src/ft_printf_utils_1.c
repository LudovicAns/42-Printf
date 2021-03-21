#include "ft_printf_utils.h"
#include "boolean.h"

int	get_numspecification(const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%' && format[i + 1] != '\0')
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
	char	c;

	c = *start_address;
	if (c == 'l')
		return (TRUE);
	return (FALSE);
}

t_boolean	is_precision(const char *start_adress)
{
	if (start_adress[0] == '.')
		return (TRUE);
	return (FALSE);
}

t_boolean	is_definer(const char *start_adress)
{
	char	definer;

	definer = *start_adress;
	if (definer == (d || i || x || big_X || c || u || p || s || percentage))
		return (TRUE);
	return (FALSE);
}
