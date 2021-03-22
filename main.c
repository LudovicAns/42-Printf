#include <stdio.h>
#include <stdarg.h>
#include "src/ft_printf.h"

int	main(void)
{
	printf("Hello ! J'ai %d ans\n", 19);
	printf("Hello ! J'ai %1d euros\n", 3900);
	printf("Hello ! J'ai %d euros\n", 200);
	printf("Hello ! J'ai %020.4d euros\n", 10000);
	printf("Hello ! J'ai %20d euros\n", 25);
	printf("Hello ! J'ai %.3d euros\n", 20);
	printf("Hello ! J'ai %.d euros\n", 300);
	return (0);
}
