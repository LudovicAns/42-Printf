#ifndef D_PROCESS_H
# define D_PROCESS_H

# include "identifier.h"

void	*get_funcomplete_d(t_identifier identifier);
int		left_justify_d(int (*complete)(int), t_identifier identifier, int count, int n);
int		process_sign_d(int (*complete)(int), t_identifier identifier, int count, int n);
int		process_number_d(t_identifier identifier, int count, int n);
int		ft_custom_nbrlen_d(int nb, t_boolean take_neg);
int		process_space_d(int (*complete)(int), t_identifier identifier, int count, int n);
int		get_precision_size_d(t_identifier identifier);
int		get_print_size_d(t_identifier identifier, int nb);
char	*ft_custom_itoa_d(int nb);

#endif