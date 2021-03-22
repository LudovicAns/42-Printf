#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "boolean.h"
# include <unistd.h>
# include <stdarg.h>
# include "specification.h"
# include "precision.h"
# include "print_configuration.h"

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
t_boolean	is_definer(const char *start_address);
t_boolean	is_precision(const char *start_address);
t_boolean	is_print_configuration(const char *start_address);
void		printchar(char c);
void		printstring(char *string);
t_boolean	is_numeric(char c);
t_boolean	is_numspecification(char c);
char		*get_specification_result(const char *start_address, va_list *args);

#endif