#include "d_process.h"
#include "identifier.h"
#include "process_utils.h"

int	left_justify_d(t_identifier identifier, int (*complete)(int), char *number,
					int count, int nb)
{
	int	i[3];

	i[0] = nb;
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	if (i[0] < 0 && !(complete == print_zero))
		count += print_char('-');
	if (i[0] >= 0 && identifier.flag.has_force_positive)
		count += print_char('+');
	count += print_zero(i[2] - ft_custom_nbrlen_d(i[0], FALSE));
	if (!(identifier.has_print_settings
			&& identifier.print_settings.has_precision_width
			&& identifier.print_settings.precision_width == 0 && i[0] == 0))
		count += print_string(number);
	else
		count += complete(i[1] - count);
	if (count < i[1])
		count += complete(i[1] - count);
	return (count);
}

static int	process_spaces_d2(t_identifier identifier, int (*complete)(int),
	int count, int nb)
{
	int	i[3];

	i[0] = nb;
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	if ((i[0] < 0 || (i[0] >= 0 && identifier.flag.has_force_positive))
		&& count == 0)
		count += complete((i[1] - count)
				- ft_abs(i[2] - ft_custom_nbrlen_d(i[0], FALSE) - i[2]) - 1);
	else
		count += complete((i[1] - count)
				- ft_abs(i[2] - ft_custom_nbrlen_d(i[0], FALSE) - i[2]));
	return (count);
}

static int	process_spaces_d(t_identifier identifier, int (*complete)(int),
	int count, int nb)
{
	int	i[3];

	i[0] = nb;
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	if (ft_custom_nbrlen_d(i[0], FALSE) < i[1] && i[1] > i[2])
	{
		if (i[2] < ft_custom_nbrlen_d(i[0], FALSE))
			count = process_spaces_d2(identifier, complete, count, i[0]);
		else
		{
			if ((i[0] < 0 || (i[0] >= 0 && identifier.flag.has_force_positive))
				&& count == 0)
				count += complete((i[1] - count) - i[2] - 1);
			else
				count += complete((i[1] - count) - i[2]);
		}
	}
	return (count);
}

int	process_number_d(t_identifier identifier, int (*complete)(int),
	char *number, int count, int nb)
{
	int	i[3];

	i[0] = nb;
	i[1] = get_print_size_d(identifier, i[0]);
	i[2] = get_precision_size_d(identifier);
	count = process_spaces_d(identifier, complete, count, i[0]);
	if (i[0] < 0 && !(complete == print_zero))
		count += print_char('-');
	if (i[0] >= 0 && identifier.flag.has_force_positive)
		count += print_char('+');
	count += print_zero(i[2] - ft_custom_nbrlen_d(i[0], FALSE));
	if (!(identifier.has_print_settings
			&& identifier.print_settings.has_precision_width
			&& identifier.print_settings.precision_width == 0 && i[0] == 0))
		count += print_string(number);
	else
		count += print_space(i[1] - count);
	return (count);
}

void	*get_funcomplete_d(t_identifier identifier)
{
	if (identifier.has_flag && identifier.flag.has_zero_filler)
	{
		if (identifier.flag.has_left_justify)
			return (print_space);
		else if (identifier.has_print_settings
			&& identifier.print_settings.has_precision_width
			&& identifier.print_settings.precision_width >= 0)
			return (print_space);
		else
			return (print_zero);
	}
	return (print_space);
}
