/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_mlx_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:09:11 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 10:36:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_win	*gen_mlx_window(void *mlx, char *title, size_t x, size_t y)
{
	t_fdf_win	*neowin;

	if (!mlx)
		fdf_error(NULL);
	neowin = check_malloc(malloc(sizeof(t_fdf_win)));
	neowin->win = mlx_new_window(mlx, x, y, title);
	if (!neowin->win)
		fdf_error(NULL);
	neowin->mlx = mlx;
	neowin->title = title;
	if (x > INT_MAX)
		fdf_error("gen_mlx_window");
	neowin->width = x;
	if (y > INT_MAX)
		fdf_error("gen_mlx_window");
	neowin->height = y;
	return (neowin);
}
