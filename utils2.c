/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:15:44 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/23 12:19:01 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_direction(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	else
		return (0);
}

void	ft_where_to_start(t_cub3d *box)
{
	int	i;
	int	x;

	x = -1;
	while (box->parsed_map[++x] != 0)
	{
		i = -1;
		while (box->parsed_map[x][++i])
		{
			if (ft_is_direction(box->parsed_map[x][i]))
			{
				box->player_x = i;
				box->player_y = x;
				if (box->parsed_map[x][i] == 'N')
					box->angle = 270;
				else if (box->parsed_map[x][i] == 'E')
					box->angle = 0;
				else if (box->parsed_map[x][i] == 'S')
					box->angle = 90;
				else if (box->parsed_map[x][i] == 'W')
					box->angle = 180;
			}
		}
	}
}

char	*ft_strdup(char *s)
{
	char	*p;
	int		i;

	p = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strncpy(char *str, int start)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (ft_strlen(str) - start));
	if (!dst)
		perror("Error\n");
	while (start < ft_strlen(str) - 1)
		dst[i++] = str[start++];
	dst[i] = '\0';
	return (dst);
}

int	ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
