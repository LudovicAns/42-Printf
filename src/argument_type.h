/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:55:24 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:55:26 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_TYPE_H
# define ARGUMENT_TYPE_H

# include "boolean.h"

typedef enum e_argument_type_char
{
	c = 'c',
	s = 's',
	p = 'p',
	d = 'd',
	i = 'i',
	u = 'u',
	x = 'x',
	X = 'X',
	percentage = '%'
}	t_argument_type_char;

typedef struct s_argument_type
{
	t_boolean				is_valid;
	t_argument_type_char	argument_type_char;
}	t_argument_type;

t_argument_type	get_argument_type(char c);

#endif
