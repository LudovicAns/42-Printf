#ifndef SPECIFICATION_H
# define SPECIFICATION_H

# include "precision.h"
# include "boolean.h"

typedef struct s_specification
{
	char		c;
	t_boolean	has_precision;
	t_precision	precision;
}	t_specification;

#endif
