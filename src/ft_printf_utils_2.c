#include "ft_printf_utils.h"

void	printstring(char *string)
{
	while (*string)
	{
		printchar(*string);
		string++;
	}
}

t_boolean	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	return (FALSE);
}

t_boolean	is_numspecification(char c)
{
	if (c == '%')
		return (TRUE);
	return (FALSE);
}

char	*get_specification_result(t_specification *specification)
{
	// Use t_specification and convert to (char *).
	return ("dd");
}

t_specification	*get_specification(const char *start_address, va_list *args)
{
	char			*s;
	int				i;
	t_specification	*specification;

	s = (char *)start_address;
	i = 1;
	specification = (t_specification *)malloc(sizeof(t_specification));
	if (!specification)
		return (NULL);
	// check for printconfiguration
	if (is_print_configuration(s[i]))
	{
		// Do smthg.
	}
	else
	{
		specification->has_print_configuration = FALSE;
		specification->print_configuration = NULL;
	}
	// check for precision
	if (is_precision(s[i]))
	{
		// Do smthg.
	}
	else
	{
		specification->has_precision = FALSE;
		specification->precision = NULL;
	}
	// here we get definer
	if (is_definer(s[i]))
		specification->definer = s[i];
	else
	{
		va_end(*args);
		return (NULL);
	}
	return (specification);
}
