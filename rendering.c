/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:58:55 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/22 16:06:28 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_ren_col_piece(t_img img, t_render render, int nb)
{
	while (render.start < render.end)
	{
		ft_render_pixel(img, nb, render.start, render.color);
		render.start++;
	}
}

static void	ft_render_column(t_img img, t_column column, int flag)
{
	t_render	render;

	if (flag == 0)
	{
		render.start = column.sky_start;
		render.end = column.sky_end;
		render.color = column.sky_color;
	}
	else if (flag == 1)
	{
		render.start = column.wall_start;
		render.end = column.wall_end;
		render.color = column.wall_color;
	}
	else
	{
		render.start = column.floor_start;
		render.end = column.floor_end;
		render.color = column.floor_color;
	}
	ft_ren_col_piece(img, render, column.colnbr);
}

static void	ft_render_wall(t_img *texture, t_img img, t_column column)
{
	unsigned int	color;
	double			textx;
	double			stepx;
	double			texty;
	int				i;

	i = 0;
	stepx = (double)texture->h / (column.wall_end - column.wall_start);
	textx = 0;
	texty = (double)texture->w * (column.currentx + column.currenty);
	while (column.wall_start < column.wall_end)
	{
		color = ft_mlx_pixel_get
			(texture, (int)texty % texture->w, (int)textx % texture->h);
		ft_render_pixel(img, column.colnbr, column.wall_start, color);
		column.wall_start++;
		textx += stepx;
		i++;
	}
	texture->currenty += stepx / texture->w;
}

static void	ft_render_walls(t_cub3d *box, t_img img, t_column column)
{
	if (column.direction == 0)
		ft_render_wall(&box->north, img, column);
	else if (column.direction == 1)
		ft_render_wall(&box->south, img, column);
	else if (column.direction == 2)
		ft_render_wall(&box->east, img, column);
	else
		ft_render_wall(&box->west, img, column);
}

void	ft_render_full_column(t_cub3d *box, t_img img, t_column column)
{
	ft_render_column(img, column, 0);
	ft_render_walls(box, img, column);
	ft_render_column(img, column, 2);
}
