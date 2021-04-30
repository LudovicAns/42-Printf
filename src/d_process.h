#ifndef D_PROCESS_H
# define D_PROCESS_H

# include "identifier.h"

int		get_precision_size_d(t_identifier identifier);
int		get_print_size_d(t_identifier identifier, int nb);
char	*ft_custom_itoa_d(int nb);
int		ft_custom_nbrlen_d(int nb, t_boolean take_neg);
int		left_justify_d(t_identifier identifier, int (*complete)(int),
			char *number, int count, int nb);
int		process_number_d(t_identifier identifier, int (*complete)(int),
			char *number, int count, int nb);
void	*get_funcomplete_d(t_identifier identifier);

#endif
