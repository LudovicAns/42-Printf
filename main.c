#include <stdio.h>
#include <stdarg.h>
#include "src/ft_printf.h"

int	main(void)
{
	int	realcount;
	int	count;

	count = ft_printf("CUSTOM   : |%-10.20s|\n", "Je suis une phrase de test.");
	realcount = printf("ORIGINAL : |%-10.20s|\n", "Je suis une phrase de test.");

	printf("===============\nBilan:\n[CUSTOM] -> %d\n[ORIGINAL] -> %d\n===============\n", count, realcount);
	return (0);
}
