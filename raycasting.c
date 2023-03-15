/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:49:34 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/22 16:45:31 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_direction(t_cub3d *box, t_ray *ray)
{
	if (ray->raycos < 0)
		ray->raycos *= -1;
	if (ray->raysin < 0)
		ray->raysin *= -1;
	if (box->parsed_map[(int)
			((ray->currenty) - ray->raysin)][(int)ray->currentx] != '1')
		ray->direction = 0;
	else if (box->parsed_map[(int)
			((ray->currenty) + ray->raysin)][(int)ray->currentx] != '1')
		ray->direction = 1;
	else if (box->parsed_map[(int)
			(ray->currenty)][(int)((ray->currentx) + ray->raycos)] != '1')
		ray->direction = 2;
	else if (box->parsed_map[(int)
			(ray->currenty)][(int)((ray->currentx) - ray->raycos)] != '1')
		ray->direction = 3;
}

static t_column	ft_do_column(t_cub3d *box, t_ray ray, int raycount)
{
	t_column	res;

	res.sky_start = 0;
	res.sky_end = box->half_h - ray.wallheight;
	if (res.sky_end < 0)
		res.sky_end = 0;
	res.sky_color = box->sky_color;
	res.wall_start = box->half_h - ray.wallheight;
	if (res.wall_start < 0)
		res.wall_start = 0;
	res.wall_end = box->half_h + ray.wallheight;
	if (res.wall_end >= box->height)
		res.wall_end = box->height;
	res.direction = ray.direction;
	res.floor_start = box->half_h + ray.wallheight;
	if (res.floor_start >= box->height)
		res.floor_start = box->height;
	res.floor_end = box->height;
	res.colnbr = raycount;
	res.currentx = ray.currentx;
	res.currenty = ray.currenty;
	res.floor_color = box->floor_color;
	return (res);
}

static void	ft_init_ray(t_cub3d *box, t_ray *ray)
{
	ray->currentx = box->player_x;
	ray->currenty = box->player_y;
	ray->raycos = cos(ft_degrees_to_radiants
			(ray->ray_angle)) / box->rc_precision;
	ray->raysin = sin(ft_degrees_to_radiants
			(ray->ray_angle)) / box->rc_precision;
}

static void	ft_raycasting2(t_cub3d *box, t_ray *ray)
{
	int			wall;

	wall = 48;
	ft_init_ray(box, ray);
	while (wall == 48 || ft_is_direction(wall) == 1)
	{
		ray->currentx += ray->raycos;
		ray->currenty += ray->raysin;
		wall = box->parsed_map
		[(int)floor(ray->currenty)][(int)floor(ray->currentx)];
	}
}

void	ft_raycasting(t_cub3d *box)
{
	int			raycount;
	t_ray		ray;
	t_column	currentcol;

	raycount = 0;
	ray.ray_angle = box->angle - box->half_fov;
	while (raycount < box->width)
	{
		ft_raycasting2(box, &ray);
		ray.dist = sqrt(pow(box->player_x - ray.currentx, 2)
				+ pow(box->player_y - ray.currenty, 2));
		ray.dist = ray.dist * cos(ft_degrees_to_radiants
				(ray.ray_angle - box->angle));
		ray.wallheight = floor(box->half_h / ray.dist);
		ft_get_direction(box, &ray);
		currentcol = ft_do_column(box, ray, raycount);
		ft_render_full_column(box, box->img, currentcol);
		ray.ray_angle += box->rc_incrementing;
		raycount++;
	}
}
