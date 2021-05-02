#ifndef PRINT_SETTINGS_H
# define PRINT_SETTINGS_H

# include "boolean.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_print_settings
{
	t_boolean	has_min_field_width;
	int			min_field_width;
	t_boolean	has_precision_width;
	int			precision_width;
}	t_print_settings;

t_boolean			is_print_settings(char c);
t_print_settings	get_print_settings(char *start_address, va_list args);
char				*skip_print_settings(char *start_address);
t_print_settings	treat_field_width(char *start_address, va_list args);
char				*get_numeric_string(char *start_address);

#endif