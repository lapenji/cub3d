/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:33:32 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/23 13:14:24 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error_n_free(t_cub3d *box, char **strarr, char *str)
{
	free(box->path_to_east);
	free(box->path_to_west);
	free(box->path_to_north);
	free(box->path_to_south);
	ft_print_error(str, strarr);
}

static void	ft_moveup_or_down3(t_cub3d *box, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = box->player_x - playercos;
	newy = box->player_y - playersin;
	if (box->parsed_map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(box->parsed_map[(int)floor(newy)]
		[(int)floor(newx)]) == 1)
	{
		box->player_x = newx;
		box->player_y = newy;
	}
}

static void	ft_moveup_or_down2(t_cub3d *box, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = box->player_x + playercos;
	newy = box->player_y + playersin;
	if (box->parsed_map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(box->parsed_map[(int)floor(newy)]
		[(int)floor(newx)]) == 1)
	{
		box->player_x = newx;
		box->player_y = newy;
	}
}

static void	ft_moveup_or_down(t_cub3d *box, int flag)
{
	double	playercos;
	double	playersin;

	playercos = cos(ft_degrees_to_radiants(box->angle)) * 0.2;
	playersin = sin(ft_degrees_to_radiants(box->angle)) * 0.2;
	if (flag == 0)
		ft_moveup_or_down2(box, playercos, playersin);
	else
		ft_moveup_or_down3(box, playercos, playersin);
}

int	ft_handlekeys(int ks, t_cub3d *box)
{
	mlx_clear_window(box->mlx_ptr, box->win_ptr);
	if (ks == KEY_A)
		box->angle -= 5;
	if (ks == KEY_D)
		box->angle += 5;
	if (ks == KEY_W)
		ft_moveup_or_down(box, 0);
	if (ks == KEY_S)
		ft_moveup_or_down(box, 1);
	if (ks == KEY_ESC)
		ft_free_n_exit(box);
	ft_raycasting(box);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img.img_ptr, 0, 0);
	return (0);
}
