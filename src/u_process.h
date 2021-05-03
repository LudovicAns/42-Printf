/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_process.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:58:47 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:58:47 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef U_PROCESS_H
# define U_PROCESS_H

# include "identifier.h"

void			*get_funcomplete_u(t_identifier identifier);
unsigned int	ft_custom_nbrlen_u(unsigned int nb);
char			*ft_custom_itoa_u(unsigned int nb);
int				get_print_size_u(t_identifier identifier, int nb);
int				get_precision_size_u(t_identifier identifier);
unsigned int	left_justify_u(t_identifier identifier, int (*complete)(int),
					char *number, unsigned int count, unsigned int nb);
unsigned int	process_spaces_u(t_identifier identifier, int (*complete)(int),
					unsigned int count, unsigned int nb);
unsigned int	process_number_u(t_identifier identifier, int (*complete)(int),
					char *number, unsigned int count, unsigned int nb);

#endif
