#include "ft_printf_utils.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	char			*res;

	va_start(args, format);
	while (*format)
	{
		format++;
	}
	va_end(args);
	return (1);
}
