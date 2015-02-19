/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:23:47 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/19 16:58:24 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_win	*first_window(void *mlx, int argnum, char **argv)
{
	t_fdf_win	*win;

	ft_putendl("Creating window...");
	if (argnum < 2)
		win = gen_mlx_window(mlx, DEF_TITLE, DEF_X, DEF_Y);
	else if (argnum == 2)
		win = gen_mlx_window(mlx,
			DEF_TITLE, ft_atoi(argv[1]), ft_atoi(argv[1]));
	else if (argnum == 3)
		win = gen_mlx_window(mlx,
			DEF_TITLE, ft_atoi(argv[1]), ft_atoi(argv[2]));
	else if (argnum == 4)
		win = gen_mlx_window(mlx,
			argv[3], ft_atoi(argv[1]), ft_atoi(argv[2]));
	if (!win)
		fdf_error(NULL);
	return (win);
}

int			main(int argc, char **argv)
{
	t_env		env;

	if (argc < 2)
	{
		ft_putstr("Usage: fractol [Fractol] [Size || X Size] [Y Size] [Title]\n");
		return (0);
	}
	ft_putendl("Initializing MLX...");
	if (argc == 2)
		env.win = first_window(mlx_init(), argc - 1, NULL);
	else
		env.win = first_window(mlx_init(), argc - 1, argv + 1);
	ft_putendl("Picking fractal...");
	env.fractal = get_fractal(argv[1]);
	env.camera = gen_default_camera();
	env.update = 0;
	new_fdf_img(env.win);
	mlx_key_hook(env.win->win, fdf_key_hook, &env);
	mlx_mouse_hook(env.win->win, fdf_mouse_hook, &env);
	mlx_hook(env.win->win, 6, (1L<<6), fdf_mouse_move_hook, &env);
	mlx_expose_hook(env.win->win, fdf_expose_hook, &env);
	mlx_loop_hook(env.win->mlx, fractal_hook, &env);
	mlx_loop(env.win->mlx);
	return (0);
}
