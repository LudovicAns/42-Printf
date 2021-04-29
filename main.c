#include <stdio.h>
#include <stdarg.h>
#include "src/ft_printf.h"

int	main(void)
{
	int	realcount;
	int	count;

	count = 0;
	count = ft_printf("CUSTOM   : |%0*d|\n", 21, -1011);
	realcount = printf("ORIGINAL : |%0*d|\n", 21, -1011);

	printf("===============\nBilan:\n[CUSTOM] -> %d\n[ORIGINAL] -> %d\n===============\n", count, realcount);
	return (0);
}
