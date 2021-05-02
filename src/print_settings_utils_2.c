#include "print_settings.h"
#include "ft_printf.h"

t_print_settings	treat_field_width(char *start_address, va_list args)
{
	t_print_settings	print_settings;
	char				*num_string;

	if (is_numeric(*start_address))
	{
		num_string = get_numeric_string(start_address);
		print_settings.has_min_field_width = TRUE;
		print_settings.min_field_width = ft_atoi(num_string);
		free(num_string);
		num_string = NULL;
		while (is_numeric(*start_address))
			start_address++;
	}
	else if (*start_address == '*')
	{
		print_settings.has_min_field_width = TRUE;
		print_settings.min_field_width = va_arg(args, int);
		start_address++;
	}
	else
		print_settings.has_min_field_width = FALSE;
	return (print_settings);
}
