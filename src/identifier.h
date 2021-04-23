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

t_boolean		is_format_identifier(char c);
t_identifier	get_identifier(char *start_address, va_list args);
char			*skip_identifier(char *start_address, char end);

#endif