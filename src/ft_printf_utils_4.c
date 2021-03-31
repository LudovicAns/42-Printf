#include "ft_printf_utils.h"

static int	ft_nbrlen(int nb)
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

	out = (char *)malloc(sizeof(char) * (ft_nbrlen(nb) + 1));
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

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1)) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
