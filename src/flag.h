#ifndef FLAG_H
# define FLAG_H

# include "boolean.h"

typedef struct s_flag
{
	t_boolean	has_left_justify;
	t_boolean	has_zero_filler;
	t_boolean	has_force_positive;
	t_boolean	has_blank_on_positive;
}	t_flag;

#endif