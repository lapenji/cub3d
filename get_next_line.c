/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:41:45 by aboncine          #+#    #+#             */
/*   Updated: 2022/10/25 13:32:54 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*taglia(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	str = my_malloc(sizeof(char) * (ft_strlen_rev(s) - i + 1));
	while (s[i])
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free (s);
	return (str);
}

char	*scrivi(int x, char *s)
{
	char	*d;

	if (s[x] == '\n')
		d = my_malloc(x + 2);
	else
		d = my_malloc(x + 1);
	x = 0;
	while (s[x] != '\n' && s[x])
	{
		d[x] = s[x];
		x++;
	}
	if (s[x] == '\n')
	{
		d[x] = '\n';
		x++;
	}
	d[x] = '\0';
	return (d);
}

char	*ft_leggi(int fd, int *i)
{
	char	*tmp;
	int		a;

	tmp = (char *) my_malloc (sizeof(char) * BUFFER_SIZE + 1);
	a = read(fd, tmp, BUFFER_SIZE);
	if (a < 0 || fd < 0 || fd > 1024)
		return (my_free(tmp));
	tmp[a] = '\0';
	*i = a;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*tmp;
	int			i;
	int			x;

	i = 1;
	while (i > 0)
	{
		x = 0;
		tmp = ft_leggi(fd, &i);
		s = ft_strjoin_rev(s, tmp);
		if (s == NULL)
			return (my_free(s));
		while (s[x] != '\n' && s[x])
			x++;
		if (s[x] == '\n' || i == 0)
		{
			tmp = scrivi(x, s);
			s = taglia (s);
			return (tmp);
		}
	}
	return (NULL);
}
