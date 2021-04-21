#include "ft_printf_utils.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_identifier	identifier;
	char			*res;

	va_start(args, format);
	while (*format)
	{
		if (is_format_identifier(*format))
		{
			// get identifier
		}
		format++;
	}
	va_end(args);
	return (1);
}
