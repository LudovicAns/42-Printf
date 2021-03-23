#ifndef SPECIFICATION_H
# define SPECIFICATION_H

# include "precision.h"
# include "boolean.h"
# include "print_configuration.h"

typedef struct s_specification
{
	char					definer;
	t_boolean				has_precision;
	t_precision				*precision;
	t_boolean				has_print_configuration;
	t_print_configuration	*print_configuration;
}	t_specification;

#endif
