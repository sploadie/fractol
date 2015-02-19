/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 12:27:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/19 17:00:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fractal_img(t_env *env)
{
	t_fdf_win	*win;
	size_t		i;
	size_t		j;
	double		x;
	double		y;

	win = env->win;
	y = (env->camera->y - ((double)(win->height / 2) * env->camera->epsilon));
	i = 0;
	while (i < win->height)
	{
		x = (env->camera->x - (
			(double)(win->width / 2) * env->camera->epsilon));
		j = 0;
		while (j < win->width)
		{
			win->img_data[(i * win->width) + j] = gen_fractal_color(env, x, y);
			x += env->camera->epsilon;
			j++;
		}
		y += env->camera->epsilon;
		i++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}
