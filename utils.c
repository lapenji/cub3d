/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:07:03 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/22 16:57:27 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *str, char **strarr)
{
	printf("%s", str);
	ft_free_map(strarr);
	exit(1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_map(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
		free(strarr[i++]);
	free(strarr);
}

void	ft_perror_exit(char *str)
{
	perror(str);
	exit (1);
}

double	ft_degrees_to_radiants(double degrees)
{
	return (degrees * PI / 180);
}
