/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:43:17 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/23 13:17:11 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_atoi_check_char(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (256);
		i++;
	}
	return (0);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (ft_atoi_check_char(nptr) == 256)
		return (256);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_start_game(char **argv)
{
	t_cub3d	box;

	ft_init_struct(&box);
	ft_create_map(&box, argv[1]);
	ft_check_map(&box);
	ft_where_to_start(&box);
	ft_create_window(&box);
	ft_create_image(&box.img, box);
	ft_init_text(&box);
	ft_raycasting(&box);
	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img.img_ptr, 0, 0);
	mlx_hook(box.win_ptr, 17, 0, ft_free_n_exit, &box);
	mlx_key_hook(box.win_ptr, ft_handlekeys, &box);
	mlx_loop(box.mlx_ptr);
}

void	check_cub(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	i--;
	if (argv[i] != 'b')
	{
		printf("Error\nMappa non valida\n");
		exit(0);
	}
	i--;
	if (argv[i] != 'u')
	{
		printf("Error\nMappa non valida\n");
		exit(0);
	}
	i--;
	if (argv[i] != 'c')
	{
		printf("Error\nMappa non valida\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_cub(argv[1]);
		ft_start_game(argv);
	}
	write(2, "Error\nparametri non validi\n", 28);
}
