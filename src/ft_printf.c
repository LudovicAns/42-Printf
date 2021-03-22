#include "ft_printf_utils.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		numspec;

	va_start(args, format);
	numspec = get_numspecification(format);
	printf("numspec = %d\n", numspec);
	while (*format)
	{
		if (is_numspecification(*format))
			printstring(get_specification_result(format, &args));
		printchar(*format);
		format++;
	}
	va_end(args);
	return (1);
}
