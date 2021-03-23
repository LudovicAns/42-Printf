#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "boolean.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
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

int						get_numspecification(const char *format);
int						get_print_size(char *start_address);
int						get_precision_size(char *start_address);
t_boolean				is_definer(const char *start_address);
t_boolean				is_precision(const char *start_address);
t_boolean				is_print_configuration(const char *start_address);
t_boolean				is_numeric(char c);
t_boolean				is_specification(char c);
void					printchar(char c);
void					printstring(char *string);
char					*get_specification_result(
							t_specification *specification);
t_specification			get_specification(const char *start_address);
t_print_configuration	*get_print_configuration(char *start_address);
t_precision				*get_precision(char *start_address);

#endif