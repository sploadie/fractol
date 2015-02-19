/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:14:35 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/19 16:44:18 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "colors.h"

# define DEF_TITLE "Fractol Main Window"
# define DEF_X 800
# define DEF_Y 800
# define DEGREE 0.0174532925

# define DEF_EPSILON 0.01
# define DEF_DEPTH 100
# define GRADIENT_SHIFT 0x0000FF
# define EPSILON_SHIFT 0.001

typedef struct		s_fdf_win
{
	void			*mlx;
	void			*win;
	char			*title;
	size_t			width;
	size_t			height;
	void			*img;
	int				*img_data;
	int				img_bits_per_pixel;
	int				img_size_line;
	int				img_endian;
}					t_fdf_win;

typedef enum		e_fractal
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	IDFK
}					t_fractal;

typedef struct		s_frac_cam
{
	double			x;
	double			y;
	double			epsilon;
	int				gradient;
	int				depth;
	int				mouse_x;
	int				mouse_y;
	double			julia_x;
	double			julia_y;
}					t_frac_cam;

typedef struct		s_env
{
	t_fdf_win		*win;
	t_fractal		fractal;
	t_frac_cam		*camera;
	int				update;
}					t_env;

//FRACTOL

t_fractal			get_fractal(char *str);
void				fractal_img(t_env *env);
int					gen_fractal_color(t_env *env, double x, double y);
void				print_camera_data(t_frac_cam *cam);

void				fdf_error(char *str);
void				*check_malloc(void *ret);

t_fdf_win			*gen_mlx_window(void *mlx, char *title, size_t x, size_t y);

void				new_fdf_img(t_fdf_win *win);
void				fdf_clear_img(t_fdf_win *win);

t_frac_cam			*gen_default_camera(void);

int					fdf_expose_hook(void *env);
int					fdf_key_hook(int keycode, void *env);
int					fdf_mouse_hook(int button, int x, int y, void *env);
int					fdf_mouse_move_hook(int x, int y, void *env_ptr);
int					fractal_hook(void *env_ptr);

//FDF

// void				fdf_cam_img(t_fdf_map *map, t_fdf_win *win);

// size_t				get_file_height(char *path);
// size_t				get_file_width(char *path);

// t_fdf_map			*fdf_map(size_t width, size_t height);
// t_fdf_map			*parse_fdf_map(char *path);

// t_3d_point			*new_3d_point(int x, int y, int z);
// void				set_3d_point(t_3d_point *point, int x, int y, int z);
// void				trans_3d_point(t_3d_point *dest, t_3d_point *src,
// 	t_fdf_cam *cam);

// void				draw_3d_point(t_3d_point *point, t_fdf_win *win);
// void				draw_point_line(t_3d_point *p1, t_3d_point *p2,
// 	t_fdf_win *win);
// void				draw_map_point_lines(size_t x, size_t y, t_fdf_map *map,
// 	t_fdf_win *win);

// void				trans_fdf_map(t_fdf_map *dest, t_fdf_map *src,
// 	t_fdf_cam *cam);

// void				print_sp_left(char *str, size_t space);
// void				print_sp_right(char *str, size_t space);

#endif
