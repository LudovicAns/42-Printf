#include <stdio.h>
#include <stdarg.h>
#include "src/ft_printf.h"

int	main(void)
{
	int	realcount;
	int	count;

	count = ft_printf("CUSTOM   : |% *i| |%+*.*i| |%-+10.5i|\n", 4, 9999, 10, 5, 42, 865);
	realcount = printf("ORIGINAL : |% *i| |%+*.*i| |%-+10.5i|\n", 4, 9999, 10, 5, 42, 865);

	printf("===============\nBilan:\n[CUSTOM] -> %d\n[ORIGINAL] -> %d\n===============\n", count, realcount);
	return (0);
}
