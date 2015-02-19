/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_fractal_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 12:47:24 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/19 12:45:36 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int		gradient_color(t_env *env, double fraction)
{
	unsigned int	color;

	color = (unsigned int)floor((double)0xFF * fraction);
	color |= (color<<8);
	color |= (color<<16);
	return (mlx_get_color_value(env->win->mlx, color));
}

static int		julia_color(t_env *env, double z_a, double z_b)
{
	double			c_x;
	double			c_y;
	double			temp;
	int				i;

	c_x = env->camera->julia_x;
	c_y = env->camera->julia_y;
	i = 0;
	while (4.0f > ((z_a * z_a) + (z_b * z_b)) && ++i < env->camera->depth)
	{
		temp = z_a;
		z_a = ((z_a * z_a) - (z_b * z_b)) + c_x;
		z_b = ((double)2.0 * temp * z_b) + c_y;
	}
	return (gradient_color(env, (double)i / (double)env->camera->depth));
}

// static int		julia_color(t_env *env, double x, double y)
// {
// 	double	hashvalue;

// 	(void)env;
// 	hashvalue = sqrt((x * x) + (y * y));
// 	if (hashvalue != 0.0)
// 		hashvalue = (double)0xFFFFFF / (hashvalue);
// 	else
// 		hashvalue = (double)0xFF0000;
// 	return (mlx_get_color_value(env->win->mlx, (int)floor(abs(hashvalue))));
// }

static int		mandelbrot_color(t_env *env, double c_x, double c_y)
{
	double			z_a;
	double			z_b;
	double			temp;
	int				i;

	z_a = c_x;
	z_b = c_y;
	i = 0;
	while (4.0f > ((z_a * z_a) + (z_b * z_b)) && ++i < env->camera->depth)
	{
		temp = z_a;
		z_a = ((z_a * z_a) - (z_b * z_b)) + c_x;
		z_b = ((double)2.0 * temp * z_b) + c_y;
	}
	return (gradient_color(env, (double)i / (double)env->camera->depth));
}

static int		burning_color(t_env *env, double c_x, double c_y)
{
	double			z_a;
	double			z_b;
	double			temp;
	int				i;

	z_a = 0;
	z_b = 0;
	i = 0;
	while (16.0f > ((z_a * z_a) + (z_b * z_b)) && ++i < env->camera->depth)
	{
		temp = z_a;
		z_a = ((z_a * z_a) - (z_b * z_b)) - c_x;
		z_b = ((double)2.0 * abs(temp * z_b)) - c_y;
	}
	return (gradient_color(env, (double)i / (double)env->camera->depth));
}

int				gen_fractal_color(t_env *env, double x, double y)
{
	if (env->fractal == JULIA)
		return (julia_color(env, x, y));
	if (env->fractal == MANDELBROT)
		return (mandelbrot_color(env, x, y));
	if (env->fractal == BURNING_SHIP)
		return (burning_color(env, x, y));
	else
	{
		fdf_error(0);
		return (0);
	}
}
