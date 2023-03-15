/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:45:16 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/22 15:48:21 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->data + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_init_text(t_cub3d *box)
{
	box->north.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, box->path_to_north,
			&box->north.w, &box->north.h);
	box->north.data = mlx_get_data_addr(box->north.img_ptr, &box->north.bpp,
			&box->north.line_len, &box->north.endian);
	box->south.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, box->path_to_south,
			&box->south.w, &box->south.h);
	box->south.data = mlx_get_data_addr(box->south.img_ptr, &box->south.bpp,
			&box->south.line_len, &box->south.endian);
	box->east.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, box->path_to_east,
			&box->east.w, &box->east.h);
	box->east.data = mlx_get_data_addr(box->east.img_ptr, &box->east.bpp,
			&box->east.line_len, &box->east.endian);
	box->west.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, box->path_to_west,
			&box->west.w, &box->west.h);
	box->west.data = mlx_get_data_addr(box->west.img_ptr, &box->west.bpp,
			&box->west.line_len, &box->west.endian);
	box->west.currenty = 0;
	box->east.currenty = 0;
	box->south.currenty = 0;
	box->north.currenty = 0;
}

void	ft_create_window(t_cub3d *box)
{
	box->height = 600;
	box->width = 800;
	box->mlx_ptr = mlx_init();
	box->win_ptr = mlx_new_window(box->mlx_ptr, box->width,
			box->height, "cub3d");
}

void	ft_create_image(t_img *img, t_cub3d box)
{
	img->img_ptr = mlx_new_image(box.mlx_ptr, box.width, box.height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
}

void	ft_render_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.data + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}
