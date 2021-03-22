#ifndef PRINT_CONFIGURATION_H
# define PRINT_CONFIGURATION_H

# include "boolean.h"

typedef struct s_print_configuration
{
	t_boolean	has_zero_filler;
	int			print_size;
}	t_print_configuration;

#endif