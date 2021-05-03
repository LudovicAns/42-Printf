/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upperx_process.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:59:11 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:59:12 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPPERX_PROCESS_H
# define UPPERX_PROCESS_H

# include "identifier.h"

void			*get_funcomplete_X(t_identifier identifier);
unsigned int	ft_custom_nbrlen_X(unsigned int nb);
char			*ft_custom_itoa_X(unsigned int nb);
int				get_print_size_X(t_identifier identifier, unsigned int nb);
int				get_precision_size_X(t_identifier identifier);
unsigned int	left_justify_X(t_identifier identifier, int (*complete)(int),
					char *number, unsigned int count, unsigned int nb);
unsigned int	process_spaces_X(t_identifier identifier, int (*complete)(int),
					unsigned int count, unsigned int nb);
unsigned int	process_number_X(t_identifier identifier, int (*complete)(int),
					char *number, unsigned int count, unsigned int nb);

#endif
