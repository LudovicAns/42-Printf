#include "ft_printf_utils.h"

/*
 * Function: get_precision			1/5
 * ----------------------------------------
 *   Returns the t_precision starting at start_address
 *
 *   *start_address: pointer of (char *) where start the precision flag
 *
 *   returns: the t_precision created or NULL if it can't be created
 */
t_precision	*get_precision(char *start_address)
{
	t_precision	*precision;
	int			precision_size;

	precision = (t_precision *)malloc(sizeof(t_precision));
	if (!precision)
		return (NULL);
	precision_size = get_precision_size(&start_address[1]);
	if (precision_size == -1)
		return (NULL);
	precision->lenght = precision_size;
	return (precision);
}

/*
 * Function: get_precision_size			2/5
 * ----------------------------------------
 *   Returns the integer value of the precision
 *
 *   *start_address: pointer of (char *) where start the precision
 *
 *   returns: the integer value of the precision
 */
int	get_precision_size(char *start_address)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (is_numeric(start_address[i]) || start_address[i] == ' ')
	{
		if (!(start_address[i++] == ' '))
			j++;
	}
	s = (char *)malloc(sizeof(char) * (j + 1));
	if (!s)
		return (-1);
	i = 0;
	j = 0;
	while (is_numeric(start_address[i]) || start_address[i] == ' ')
	{
		if (is_numeric(start_address[i]))
			s[j++] = start_address[i];
		i++;
	}
	s[j] = '\0';
	// Don't forget to replace this atoi by mind.
	j = atoi(s);
	free(s);
	return (j);
}

/*
 * Function: get_print_configuration			3/5
 * ----------------------------------------
 *   Returns the t_print_configuration starting at start_address
 *
 *   *start_address: pointer of (char *) where start the print_configuration flag
 *
 *   returns: the t_print_configuration created or NULL if it can't be created
 */
t_print_configuration	*get_print_configuration(char *start_address)
{
	t_print_configuration	*pconf;
	int						i;
	int						print_size;

	pconf = (t_print_configuration *)malloc(sizeof(t_print_configuration));
	if (!pconf)
		return (NULL);
	i = 0;
	if (start_address[i] == '0')
	{
		pconf->has_zero_filler = TRUE;
		i++;
	}
	else
		pconf->has_zero_filler = FALSE;
	print_size = get_print_size(&start_address[i]);
	if (print_size == -1)
		return (NULL);
	pconf->print_size = print_size;
	return (pconf);
}

/*
 * Function: get_print_size			4/5
 * ----------------------------------------
 *   Returns the integer value of the print_configuration
 *
 *   *start_address: pointer of (char *) where start the print_configuration
 *
 *   returns: the integer value of the print_configuration
 */
int	get_print_size(char *start_address)
{
	int		i;
	int		j;
	int		count;
	char	*s;

	i = 0;
	count = 0;
	while (is_numeric(start_address[i]) || start_address[i] == ' ')
	{
		if (!(start_address[i++] == ' '))
			count++;
	}
	i = 0;
	s = (char *)malloc(sizeof(char) * (count + 1));
	if (!s)
		return (-1);
	j = 0;
	while (is_numeric(start_address[i]) || start_address[i] == ' ')
	{
		if (is_numeric(start_address[i]))
			s[j++] = start_address[i];
		i++;
	}
	s[j] = '\0';
	// Don't forget to replace this atoi by mind.
	count = atoi(s);
	free(s);
	return (count);
}
