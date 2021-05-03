/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:58:05 by lanselin          #+#    #+#             */
/*   Updated: 2021/05/03 09:58:06 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "process_utils.h"

int	ft_nbrlen(int nb)
{
	unsigned int	nui;
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nui = -nb;
		i++;
	}
	else
		nui = nb;
	while (nui)
	{
		nui /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	unsigned int	nui;
	char			*out;
	int				i;

	out = (char *)malloc(sizeof(char) * ft_nbrlen(nb) + 1);
	if (!out)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		nui = -nb;
		out[i++] = '-';
	}
	else
		nui = nb;
	i = ft_nbrlen(nb) - 1;
	while (nui)
	{
		out[i--] = (nui % 10) + '0';
		nui /= 10;
	}
	if (nb == 0)
		out[i] = '0';
	out[ft_nbrlen(nb)] = '\0';
	return (out);
}

int	print_string(char *string)
{
	int	count;

	count = 0;
	while (*string)
	{
		count += print_char(*string);
		string++;
	}
	return (count);
}

int	print_space(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		return (0);
	while (nb-- != 0)
	{
		print_char(' ');
		count++;
	}
	return (count);
}

int	print_zero(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		return (0);
	while (nb-- != 0)
	{
		print_char('0');
		count++;
	}
	return (count);
}
