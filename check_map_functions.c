/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:16:40 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/23 13:15:02 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_valid_path2(t_cub3d *box, int j, int i, int number_of_rows)
{
	if (i < ft_strlen(box->map[j]) - 2)
	{
		if (box->map[j][i + 1] != '1' && box->map[j][i + 1] != ' '
			&& box->map[j][i + 1] != 11)
			ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
		else if (box->map[j][i + 1] == ' ')
			ft_check_valid_path(box, j, (i + 1), number_of_rows);
	}
	if (i > 0)
	{
		if (box->map[j][i - 1] != '1' && box->map[j][i - 1] != ' '
			&& box->map[j][i - 1] != 11)
			ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
		else if (box->map[j][i - 1] == ' ')
			ft_check_valid_path(box, j, (i - 1), number_of_rows);
	}
}

static void	ft_check_valid_path3(t_cub3d *box, int j, int i, int number_of_rows)
{
	if (j < number_of_rows - 1)
	{
		if (box->map[j + 1][i] != '1' && box->map[j + 1][i] != ' '
			&& box->map[j + 1][i] != 11)
			ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
		else if (box->map[j + 1][i] == ' ')
			ft_check_valid_path(box, (j + 1), i, number_of_rows);
	}
	if (j > 0)
	{
		if (box->map[j - 1][i] != '1' && box->map[j - 1][i] != ' '
			&& box->map[j - 1][i] != 11)
			ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
		else if (box->map[j - 1][i] == ' ')
			ft_check_valid_path(box, (j - 1), i, number_of_rows);
	}
}

void	ft_check_valid_path(t_cub3d *box, int j, int i, int n_of_r)
{
	box->map[j][i] = 11;
	ft_check_valid_path2(box, j, i, n_of_r);
	ft_check_valid_path3(box, j, i, n_of_r);
}

void	ft_second_check(t_cub3d *box)
{
	if (box->i != ft_strlen(box->map[box->j]) - 1)
	{
		if (box->map[box->j][box->i] != 'N' && box->map[box->j][box->i] != 'S'
			&& box->map[box->j][box->i] != 'W'
			&& box->map[box->j][box->i] != 'E'
			&& box->map[box->j][box->i] != '0'
			&& box->map[box->j][box->i] != '1'
			&& box->map[box->j][box->i] != ' '
			&& box->map[box->j][box->i] != 11)
			ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
	}
	if (box->map[box->j][box->i] == 'N' || box->map[box->j][box->i] == 'S'
		|| box->map[box->j][box->i] == 'W' || box->map[box->j][box->i] == 'E'
		|| box->map[box->j][box->i] == '0')
	{
		if (!box->map[box->j + 1][box->i] || !box->map[box->j - 1][box->i]
			|| (box->flag == 1 && box->map[box->j][box->i] != '0')
			|| box->map[box->j - 1][box->i] == ' '
			|| box->map[box->j + 1][box->i] == ' '
			|| box->map[box->j - 1][box->i] == 11
			|| box->map[box->j + 1][box->i] == 11)
			ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
		if (box->map[box->j][box->i] != '0')
			box->flag = 1;
	}
}

void	ft_first_check(t_cub3d *box, int tmp)
{
	if (box->j == tmp || box->j == box->number_of_rows - 1)
	{
		while (box->map[box->j][box->i] != '\n')
		{
			if (box->map[box->j][box->i] != '1'
				&& box->map[box->j][box->i] != ' '
				&& box->map[box->j][box->i] != 11)
				ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
			box->i++;
		}
		box->i = 0;
	}
	if ((box->map[box->j][0] != '1' && box->map[box->j][0] != ' '
		&& box->map[box->j][0] != 11)
		|| (box->map[box->j][ft_strlen(box->map[box->j]) - 2] != '1'
		&& box->map[box->j][ft_strlen(box->map[box->j]) - 2] != ' '
		&& box->map[box->j][ft_strlen(box->map[box->j]) - 2] != 11))
		ft_print_error_n_free(box, box->map, "Error\nmappa non valida\n");
}
