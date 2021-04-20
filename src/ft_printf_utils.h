#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "boolean.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_definer
{
	d = 'd',
	x = 'x',
	big_X = 'X',
	c = 'c',
	i = 'i',
	u = 'u',
	p = 'p',
	s = 's',
	percentage = '%'
}	t_definer;

#endif