/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_process.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:59:32 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:59:33 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_PROCESS_H
# define X_PROCESS_H

# include "identifier.h"

void			*get_funcomplete_x(t_identifier identifier);
unsigned int	ft_custom_nbrlen_x(unsigned int nb);
char			*ft_custom_itoa_x(unsigned int nb);
int				get_print_size_x(t_identifier identifier, unsigned int nb);
int				get_precision_size_x(t_identifier identifier);
unsigned int	left_justify_x(t_identifier identifier, int (*complete)(int),
					char *number, unsigned int count, unsigned int nb);
unsigned int	process_spaces_x(t_identifier identifier, int (*complete)(int),
					unsigned int count, unsigned int nb);
unsigned int	process_number_x(t_identifier identifier, int (*complete)(int),
					char *number, unsigned int count, unsigned int nb);

#endif
