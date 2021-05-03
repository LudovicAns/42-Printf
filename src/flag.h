/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:56:05 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:56:06 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# include "boolean.h"
# include "unistd.h"

typedef struct s_flag
{
	t_boolean	has_left_justify;
	t_boolean	has_zero_filler;
	t_boolean	has_force_positive;
	t_boolean	has_blank_on_positive;
	t_boolean	has_sharp;
}	t_flag;

typedef enum e_flag_type
{
	LEFT_JUSTIFY = '-',
	ZERO_FILLER = '0',
	FORCE_POSITIVE = '+',
	BLANK_ON_POSITIVE = ' ',
	SHARP = '#'
}	t_flag_type;

t_boolean	is_flag_type(char c);
t_flag_type	get_flag_type(char c);
void		set_flag_type(t_flag_type flag_type, t_boolean b, t_flag *flag);
t_flag		get_flag(char *start_address);
char		*skip_flags(char *start_address);

#endif
