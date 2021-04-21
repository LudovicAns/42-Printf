#ifndef PRINT_SETTINGS_H
# define PRINT_SETTINGS_H

# include "boolean.h"

typedef struct s_print_settings
{
	t_boolean	has_min_field_width;
	int			min_field_width;
	t_boolean	has_precision_width;
	int			precision_width;
}	t_print_settings;

#endif