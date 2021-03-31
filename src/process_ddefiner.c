#include "ft_printf_utils.h"

static int	get_size(t_specification spec, char *nb)
{
	if (spec.has_print_configuration
		&& spec.print_configuration->print_size != 0)
		return (spec.print_configuration->print_size);
	else
		return (ft_strlen(nb));
}

static char	*malloc_result(t_specification spec, char *nb)
{
	int		size;
	char	*result;

	if (spec.has_print_configuration
		&& spec.print_configuration->print_size != 0)
		size = spec.print_configuration->print_size;
	else
		size = ft_strlen(nb);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	return (result);
}

static char	*process(char *nb, int size, t_specification spec, char *result)
{
	int	j;
	int	i;

	i = 0;
	if (ft_strlen(nb) < size)
	{
		if (spec.print_configuration->has_zero_filler)
		{
			while (size-- != ft_strlen(nb))
				result[i++] = '0';
		}
		else
		{
			while (size-- != ft_strlen(nb))
				result[i++] = ' ';
		}
		j = 0;
		while (size-- >= 0)
			result[i++] = nb[j++];
		result[i] = '\0';
		secure_free(nb);
		return (result);
	}
	secure_free(result);
	return (nb);
}

char	*process_ddefiner(t_specification spec, va_list *args)
{
	char	*nb;
	char	*result;

	nb = ft_itoa(va_arg(*args, int));
	result = malloc_result(spec, nb);
	return (process(nb, get_size(spec, nb), spec, result));
}
