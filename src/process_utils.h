#ifndef PROCESS_UTILS_H
# define PROCESS_UTILS_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

int		ft_nbrlen(int nb);
char	*ft_itoa(int nb);
int		print_string(char *string);
int		print_space(int nb);
int		print_zero(int nb);
int		ft_abs(int i);

#endif