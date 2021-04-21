#ifndef IDENTIFIER_H
# define IDENTIFIER_H

# include "flag.h"
# include "print_settings.h"
# include "argument_type.h"
# include "boolean.h"

typedef struct s_identifier
{
	t_boolean			has_flag;
	t_flag				flag;
	t_boolean			has_print_settings;
	t_print_settings	print_settings;
	t_argument_type		argument_type;
}	t_identifier;

#endif