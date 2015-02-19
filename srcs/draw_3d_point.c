/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 16:49:07 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 10:27:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_3d_point(t_3d_point *point, t_fdf_win *win)
{
	int		x;
	int		y;

	x = (int)(win->width / 2) + point->x;
	y = (int)(win->height / 2) - point->y;
	if (x < 0 || x >= (int)win->width ||
		y < 0 || y >= (int)win->height ||
		point->z > 0)
		return ;
	win->img_data[(y * win->width) + (x)] =
		(int)floor(0x555555 + (point->origin_z * 0x000011));
}
