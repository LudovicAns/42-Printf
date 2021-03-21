#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "boolean.h"

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

int			get_numspecification(const char *format);
t_boolean	is_definer(const char *start_adress);
t_boolean	is_precision(const char *start_adress);
t_boolean	is_print_configuration(const char *start_address);

#endif