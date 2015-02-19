/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:42:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/19 11:44:46 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_camera_data(t_frac_cam *cam)
{
	char	float_string[100];

	ft_putstr("Cam: ");
	// ft_putstr("x (x10,000): ");
	// ft_putnbr((int)floor(cam->x * 10000));
	sprintf(float_string, "x: %f", cam->x);//FIXME
	ft_putstr(float_string);//FIXME
	// ft_putstr(" y (x10,000): ");
	// ft_putnbr((int)floor(cam->y * 10000));
	sprintf(float_string, " y: %f", cam->y);//FIXME
	ft_putstr(float_string);//FIXME
	// ft_putstr(" epsilon (x10,000): ");
	// ft_putnbr((int)floor(cam->epsilon * 10000));
	sprintf(float_string, " epsilon: %.14f", cam->epsilon);//FIXME
	ft_putstr(float_string);//FIXME
	ft_putstr(" gradient: ");
	ft_putnbr(cam->gradient);
	ft_putstr(" depth: ");
	ft_putnbr(cam->depth);
	ft_putstr(" mouse_x: ");
	ft_putnbr(cam->mouse_x);
	ft_putstr(" mouse_y: ");
	ft_putnbr(cam->mouse_y);
	sprintf(float_string, " julia_x: %.14f", cam->julia_x);//FIXME
	ft_putstr(float_string);//FIXME
	sprintf(float_string, " julia_y: %.14f", cam->julia_y);//FIXME
	ft_putstr(float_string);//FIXME
	write(1, " ", 1);
}

int		fractal_hook(void *env_ptr)
{
	static int		displaying = 0;
	t_env			*env;
	double			calc_time;
	char			float_string[100];

	env = env_ptr;
	if (displaying == 1)
		return (0);
	if (!env->update)
		return (0);
	displaying = 1;
	env->update = 0;
	print_camera_data(env->camera);
	ft_putstr("Redrawing Image... ");
	calc_time = (double)clock();
	fractal_img(env);
	calc_time = ((double)clock() - calc_time) / CLOCKS_PER_SEC;
	sprintf(float_string, " done in %.10f seconds.\n", calc_time);//FIXME
	ft_putstr(float_string);//FIXME
	// ft_putstr("done.\n");
	displaying = 0;
	return (0);
}

// int		fractal_hook(void *env_ptr)
// {
// 	static clock_t	last_check = 0;
// 	t_env			*env;
// 	double			calc_time;
// 	char			float_string[100];

// 	env = env_ptr;
// 	if (last_check > clock())
// 		return (0);
// 	if (!env->update)
// 		return (0);
// 	last_check = clock() + (CLOCKS_PER_SEC / 10.0f);
// 	env->update = 0;
// 	print_camera_data(env->camera);
// 	ft_putstr("Redrawing Image... ");
// 	calc_time = (double)clock();
// 	fractal_img(env);
// 	calc_time = ((double)clock() - calc_time) / CLOCKS_PER_SEC;
// 	sprintf(float_string, " done in %.10f seconds.\n", calc_time);//FIXME
// 	ft_putstr(float_string);//FIXME
// 	// ft_putstr("done.\n");
// 	return (0);
// }