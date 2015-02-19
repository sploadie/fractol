/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:08:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/19 17:00:33 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_mouse_hook(int button, int x, int y, void *env_ptr)
{
	t_env			*env;
	double			epsilon_shift;
	static int		rolling = 0;
	static clock_t	next_pass = 0;

	env = env_ptr;
	if (button == 1)
	{
		env->camera->x = env->camera->x + (((double)x - (
			(double)env->win->width / 2.0)) * env->camera->epsilon);
		env->camera->y = env->camera->y + (((double)y - (
			(double)env->win->height / 2.0)) * env->camera->epsilon);
	}
	else if (rolling == 0 && clock() > next_pass)
	{
		rolling = 1;
		next_pass = clock() + (CLOCKS_PER_SEC / 10.0f);
		epsilon_shift = 5.0f;
		while (env->camera->epsilon < epsilon_shift * 2.0f
			&& epsilon_shift > 0.0000000000001f)
			epsilon_shift /= 10.0f;
		if (epsilon_shift <= 0.0000000000001f)
			epsilon_shift = 0.0000000000001f;
		if (button == 7)
			env->camera->epsilon -= epsilon_shift;
		else if (button == 6)
			env->camera->epsilon += epsilon_shift;
		else if (button == 5)
			env->camera->epsilon += epsilon_shift;
		else if (button == 4)
			env->camera->epsilon -= epsilon_shift;
		if (env->camera->epsilon <= 0.000000000001f)
			env->camera->epsilon = 0.000000000001f;
		rolling = 0;
	}
	env->update = 1;
	return (0);
}

int		fdf_mouse_move_hook(int x, int y, void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	env->camera->mouse_x = x - (env->win->width / 2);
	env->camera->mouse_y = y - (env->win->height / 2);
	env->camera->julia_x = ((double)x - (
		(double)env->win->width / 2)) * (3.0f / (double)env->win->width);
	env->camera->julia_y = ((double)y - (
		(double)env->win->height / 2)) * (3.0f / (double)env->win->height);
	if (env->fractal == JULIA)
		env->update = 1;
	return (0);
}
