/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:39:50 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/23 12:26:44 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"
# define PI 3.141592653589793

typedef struct s_render
{
	int	start;
	int	end;
	int	color;
}				t_render;

typedef struct s_img
{
	void	*img_ptr;
	int		w;
	int		h;
	int		bpp;
	int		line_len;
	int		endian;
	char	*data;
	int		currenty;
}				t_img;

typedef struct s_ray
{
	double	ray_angle;
	double	currentx;
	double	currenty;
	double	raycos;
	double	raysin;
	double	dist;
	double	wallheight;
	int		direction;
}				t_ray;

typedef struct s_column
{
	int		sky_start;
	int		sky_end;
	int		sky_color;
	int		wall_start;
	int		wall_end;
	int		wall_color;
	int		floor_start;
	int		floor_end;
	int		floor_color;
	int		colnbr;
	int		direction;
	double	currenty;
	double	currentx;
}				t_column;

typedef struct s_cub3d
{
	int				rdelay;
	int				rc_precision;
	int				width;
	int				height;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	char			**parsed_map;
	double			half_h;
	double			half_w;
	double			fov;
	double			half_fov;
	double			player_x;
	double			player_y;
	double			angle;
	double			rc_incrementing;
	int				i;
	int				j;
	int				number_of_rows;
	int				flag;
	unsigned int	sky_color;
	unsigned int	floor_color;
	char			*path_to_north;
	char			*path_to_south;
	char			*path_to_east;
	char			*path_to_west;
	t_img			img;
	t_img			north;
	t_img			south;
	t_img			west;
	t_img			east;
}				t_cub3d;
//KEYS
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_E 101
# define KEY_Q 113
# define KEY_R 114
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
//HOOKS.c
int				ft_handlekeys(int ks, t_cub3d *box);
//RAYCASTING.c
void			ft_raycasting(t_cub3d *box);
//RENDER.c
void			ft_render_full_column(t_cub3d *box, t_img img, t_column column);
//MLX_UTILS.c
void			ft_create_image(t_img *img, t_cub3d box);
void			ft_render_pixel(t_img img, int x, int y, int color);
void			ft_create_window(t_cub3d *box);
void			ft_init_text(t_cub3d *box);
unsigned int	ft_mlx_pixel_get(t_img *data, int x, int y);
//INIT.c
void			ft_init_struct(t_cub3d *box);
void			ft_create_map(t_cub3d *box, char *argv);
int				ft_free_n_exit(t_cub3d *box);
//UTILS.c
double			ft_degrees_to_radiants(double degrees);
void			ft_perror_exit(char *str);
void			ft_check_map(t_cub3d *box);
int				ft_strlen(char *str);
void			ft_print_error(char *str, char **strarr);
void			ft_first_check(t_cub3d *box, int tmp);
void			ft_check_valid_path(t_cub3d *box, int j, int i, int n_of_r);
void			ft_second_check(t_cub3d *box);
void			ft_free_map(char **strarr);
int				ft_strncmp(char *s1, char *s2);
char			*ft_strncpy(char *str, int start);
char			*ft_strdup(char *s);
unsigned int	ft_get_rgb(t_cub3d *box, char *s, int start);
void			ft_where_to_start(t_cub3d *box);
int				ft_is_direction(char c);
void			ft_print_error_n_free(t_cub3d *box, char **strarr, char *str);
long			ft_atoi(const char *nptr);

#endif
