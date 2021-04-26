#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "identifier.h"
# include "boolean.h"
# include "print_settings.h"
# include "flag.h"
# include "process_utils.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int			ft_printf(const char *format, ...);
t_boolean	is_numeric(char c);
int			print_char(char c);
int			launch_associated_process(t_identifier identifier, va_list args);
int			process_c(t_identifier identifier, va_list args);
int			process_d(t_identifier identifier, va_list args);
int			process_i(t_identifier identifier, va_list args);
int			process_p(t_identifier identifier, va_list args);
int			process_percentage(t_identifier identifier, va_list args);
int			process_s(t_identifier identifier, va_list args);
int			process_u(t_identifier identifier, va_list args);
int			process_x(t_identifier identifier, va_list args);
int			process_X(t_identifier identifier, va_list args);

#endif