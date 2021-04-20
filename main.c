#include <stdio.h>
#include <stdarg.h>
#include "src/ft_printf.h"

int	main(void)
{
	ft_printf("\n\n\n");
	printf("J'ai %100.10d ans et j'ai %1d patates.\n", 10, 4, 5800, 200);
	ft_printf("J'ai %20d ans et j'ai %1d patates.\n", 25, 5800);
	//ft_printf("Avoir %3d euros est mon rêve !\n", 100000000);
	return (0);
}
