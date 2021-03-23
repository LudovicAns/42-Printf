#include "ft_printf_utils.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				numspec;
	t_specification	spec;

	va_start(args, format);
	numspec = get_numspecification(format);
	printf("numspec = %d\n", numspec);
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
			printf("pcong = %d | precision = %d | definer = %c\n",
				spec.has_print_configuration, spec.has_precision,
				spec.definer);
			if (spec.has_print_configuration)
			{
				printf("zero filler = %d | size = %d\n",
					spec.print_configuration->has_zero_filler,
					spec.print_configuration->print_size);
			}
			if (spec.has_precision)
			{
				printf("precision size = %d\n",
					spec.precision->lenght);
			}
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
