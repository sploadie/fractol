/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_fractal_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 12:47:24 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/19 16:42:32 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** static unsigned int		gradient_color(t_env *env, double fraction)
** {
** 	unsigned int	color;
** 
** 	color = (unsigned int)floor((double)0xFF * fraction);
** 	color |= (color<<8);
** 	color |= (color<<16);
** 	return (mlx_get_color_value(env->win->mlx, color));
** }
*/

static unsigned int		gradient_color(t_env *env, double fraction)
{
	unsigned int	color;

	color = 0;
	if (fraction > 0.75f)
	{
		fraction -= 0.75f;
		fraction *= 4.0f;
		color |= (((unsigned int)0xFF)<<16);
		color |= (((unsigned int)floor((double)0xFF * fraction))<<8);
		color |= (((unsigned int)floor((double)0xFF * fraction))<<0);
		return (mlx_get_color_value(env->win->mlx, color));
	}
	if (fraction > 0.50f)
	{
		fraction -= 0.50f;
		fraction *= 4.0f;
		color |= (((unsigned int)floor((double)0xFF * fraction))<<16);
		color |= (((unsigned int)floor((double)0xFF * (1 - fraction)))<<8);
		return (mlx_get_color_value(env->win->mlx, color));
	}
	if (fraction > 0.25f)
	{
		fraction -= 0.25f;
		fraction *= 4.0f;
		color |= (((unsigned int)floor((double)0xFF * fraction))<<8);
		color |= (((unsigned int)floor((double)0xFF * (1 - fraction)))<<0);
		return (mlx_get_color_value(env->win->mlx, color));
	}
	fraction *= 4.0f;
	color |= (((unsigned int)floor((double)0xFF * fraction))<<0);
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

	z_a = c_x  * -1;
	z_b = c_y  * -1;
	i = 0;
	while (10.0f > ((z_a * z_a) + (z_b * z_b)) && ++i < env->camera->depth)
	{
		temp = z_a;
		z_a = ((z_a * z_a) - (z_b * z_b)) - c_x;
		z_b = (2.0f * fabs(temp * z_b)) - c_y;
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
		return (burning_color(env, x, y * -1.0f));
	else
	{
		fdf_error(0);
		return (0);
	}
}
