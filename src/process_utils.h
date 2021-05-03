/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:57:57 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:57:57 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
