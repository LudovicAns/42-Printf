#include "ft_printf_utils.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_specification	spec;
	char			*res;

	va_start(args, format);
	while (*format)
	{
		if (is_specification(*format))
		{
			spec = get_specification(format);
			if (!spec.definer)
			{
				printchar(*format);
				format++;
				continue ;
			}
			res = get_specification_result(spec, &args);
			printstring(res);
			// free res here
			free(spec.print_configuration);
			spec.print_configuration = NULL;
			free(spec.precision);
			spec.precision = NULL;
			while (*format != spec.definer)
				format++;
			format++;
		}
		printchar(*format);
		format++;
	}
	va_end(args);
	return (1);
}

// Don't forget to free $spec and pointer in $spec.
