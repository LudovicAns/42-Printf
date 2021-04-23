#include <stdio.h>
#include <stdarg.h>
#include "src/ft_printf.h"

int	main(void)
{
	int	realcount;
	int	count;

	count = ft_printf("Impression du caractère : |%-*c|\n", 5, 'i');
	realcount = printf("Impression du caractère : |%-*c|\n", 5, 'i');

	printf("===============\nBilan:\n[CUSTOM] -> %d\n[ORIGINAL] -> %d\n===============\n", count, realcount);
	return (0);
}
