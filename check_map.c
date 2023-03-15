/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:12:56 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/23 13:15:30 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_path(t_cub3d *box)
{
	int	fd;

	if (box->path_to_north == NULL || box->path_to_south == NULL
		|| box->path_to_east == NULL || box->path_to_west == NULL)
		ft_print_error_n_free(box, box->map, "Error\ntexture non valida\n");
	fd = open(box->path_to_east, O_RDONLY);
	if (fd < 0)
		ft_print_error_n_free(box, box->map, "Error\ntexture EA non valida\n");
	close (fd);
	fd = open(box->path_to_west, O_RDONLY);
	if (fd < 0)
		ft_print_error_n_free(box, box->map, "Error\ntexture WE non valida\n");
	close (fd);
	fd = open(box->path_to_north, O_RDONLY);
	if (fd < 0)
		ft_print_error_n_free(box, box->map, "Error\ntexture NO non valida\n");
	close (fd);
	fd = open(box->path_to_south, O_RDONLY);
	if (fd < 0)
		ft_print_error_n_free(box, box->map, "Error\ntexture SO non valida\n");
	close (fd);
}

static void	ft_parsed_map(t_cub3d *box, int tmp)
{
	int	i;

	i = 0;
	box->parsed_map = (char **) malloc
		(sizeof(char*) * (box->number_of_rows - tmp + 1));
	if (!box->parsed_map)
	{
		ft_free_map(box->map);
		ft_perror_exit("Error\n");
	}
	while (tmp < box->number_of_rows)
		box->parsed_map[i++] = ft_strdup(box->map[tmp++]);
	box->parsed_map[i] = 0;
}

static void	ft_do_check(t_cub3d *box, int tmp)
{
	while (box->map[box->j])
	{
		ft_first_check(box, tmp);
		while (box->map[box->j][box->i])
		{
			ft_second_check(box);
			if (box->map[box->j][box->i] == ' ')
				ft_check_valid_path(box, box->j, box->i, box->number_of_rows);
			box->i++;
		}
		box->i = 0;
		box->j++;
	}
	if (box->flag == 0)
		ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
	ft_parsed_map(box, tmp);
}

static void	ft_check_parameters(t_cub3d *box)
{
	if (ft_strncmp(box->map[box->j], "NO ") == 1)
		box->path_to_north = ft_strncpy(box->map[box->j], 3);
	else if (ft_strncmp(box->map[box->j], "SO ") == 1)
		box->path_to_south = ft_strncpy(box->map[box->j], 3);
	else if (ft_strncmp(box->map[box->j], "WE ") == 1)
		box->path_to_west = ft_strncpy(box->map[box->j], 3);
	else if (ft_strncmp(box->map[box->j], "EA ") == 1)
		box->path_to_east = ft_strncpy(box->map[box->j], 3);
	else if (ft_strncmp(box->map[box->j], "F ") == 1)
		box->floor_color = ft_get_rgb(box, box->map[box->j], 2);
	else if (ft_strncmp(box->map[box->j], "C ") == 1)
		box->sky_color = ft_get_rgb(box, box->map[box->j], 2);
}

void	ft_check_map(t_cub3d *box)
{
	int	tmp;

	box->i = 0;
	box->j = 0;
	box->number_of_rows = 0;
	box->flag = 0;
	while (box->map[box->j])
	{
		box->number_of_rows++;
		box->j++;
	}
	tmp = box->number_of_rows;
	box->j = 0;
	while (box->map[box->j])
	{
		ft_check_parameters(box);
		box->j++;
	}
	ft_check_path(box);
	while (tmp != 0 && (box->map[tmp - 1][0] == ' '
		|| box->map[tmp - 1][0] == '1'))
		tmp--;
	box->j = tmp;
	ft_do_check(box, tmp);
}
