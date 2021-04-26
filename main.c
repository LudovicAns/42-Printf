#include <stdio.h>
#include <stdarg.h>
#include "src/ft_printf.h"

int	main(void)
{
	int	realcount;
	int	count;

	count = ft_printf("CUSTOM   : |%-u|\n", 42);
	realcount = printf("ORIGINAL : |%-u|\n", 42);

	printf("===============\nBilan:\n[CUSTOM] -> %d\n[ORIGINAL] -> %d\n===============\n", count, realcount);
	return (0);
}
