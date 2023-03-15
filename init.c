/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:41:13 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/23 13:00:27 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_create_map_2(t_cub3d *box, int count, int fd, char *argv)
{
	int		i;

	i = 0;
	box->map = (char **) malloc(sizeof(char *) * (count + 1));
	if (!box->map)
		ft_perror_exit("Error allocation memory");
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_perror_exit("Error\n");
	while (i < count)
		box->map[i++] = get_next_line(fd);
	box->map[i] = 0;
	close(fd);
}

void	ft_create_map(t_cub3d *box, char *argv)
{
	int		fd;
	int		count;
	char	*tmp;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_perror_exit("Error\n");
	tmp = get_next_line(fd);
	if (tmp != NULL)
		count++;
	else
		ft_perror_exit("Error\n");
	while (tmp != NULL)
	{
		free (tmp);
		tmp = get_next_line(fd);
		count++;
	}
	ft_create_map_2(box, count, fd, argv);
}

void	ft_init_struct(t_cub3d *box)
{
	box->width = 800;
	box->height = 600;
	box->half_h = box->height / 2;
	box->half_w = box->width / 2;
	box->rdelay = 30;
	box->fov = 66;
	box->half_fov = 0;
	box->player_x = 2;
	box->player_y = 2;
	box->angle = 360;
	box->rc_precision = 64;
	box->rc_incrementing = box->fov / box->width;
	box->half_fov = box->fov / 2;
	box->path_to_north = NULL;
	box->path_to_south = NULL;
	box->path_to_east = NULL;
	box->path_to_west = NULL;
}

int	ft_free_n_exit(t_cub3d *box)
{
	mlx_destroy_image(box->mlx_ptr, box->north.img_ptr);
	mlx_destroy_image(box->mlx_ptr, box->south.img_ptr);
	mlx_destroy_image(box->mlx_ptr, box->east.img_ptr);
	mlx_destroy_image(box->mlx_ptr, box->west.img_ptr);
	mlx_destroy_image(box->mlx_ptr, box->img.img_ptr);
	mlx_destroy_window(box->mlx_ptr, box->win_ptr);
	mlx_destroy_display(box->mlx_ptr);
	free(box->mlx_ptr);
	free(box->path_to_east);
	free(box->path_to_west);
	free(box->path_to_north);
	free(box->path_to_south);
	ft_free_map(box->map);
	ft_free_map(box->parsed_map);
	exit(0);
	return (0);
}
