/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:16:36 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 12:25:18 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_per_x(t_3d_point p1, t_3d_point p2, t_fdf_win *win)
{
	double	m;
	double	b;
	int		plus;
	double	z_calc;
	double	z_plus;

	m = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	b = (double)p1.y - ((double)p1.x * m);
	plus = ((p1.x < p2.x) ? 1 : -1);
	z_calc = (double)p1.origin_z;
	z_plus = (double)abs(p2.x - p1.x);
	if (!z_plus)
		z_plus = 1;
	z_plus = (double)(p2.origin_z - p1.origin_z) / z_plus;
	while (p1.x != p2.x)
	{
		p1.x += plus;
		p1.y = (int)floor(((double)p1.x * m) + b);
		z_calc += z_plus;
		p1.origin_z = (float)floor(z_calc);
		draw_3d_point(&p1, win);
	}
}

static void	draw_per_y(t_3d_point p1, t_3d_point p2, t_fdf_win *win)
{
	double	m;
	double	b;
	int		plus;
	double	z_calc;
	double	z_plus;

	m = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	b = (double)p1.x - ((double)p1.y / m);
	plus = ((p1.y < p2.y) ? 1 : -1);
	z_calc = (double)p1.origin_z;
	z_plus = (double)abs(p2.y - p1.y);
	if (!z_plus)
		z_plus = 1;
	z_plus = (double)(p2.origin_z - p1.origin_z) / z_plus;
	while (p1.y != p2.y)
	{
		p1.y += plus;
		p1.x = (int)floor(((double)p1.y / m) + b);
		z_calc += z_plus;
		p1.origin_z = (int)floor(z_calc);
		draw_3d_point(&p1, win);
	}
}

void		draw_point_line(t_3d_point *p1, t_3d_point *p2, t_fdf_win *win)
{
	draw_3d_point(p1, win);
	draw_per_y(*p1, *p2, win);
	draw_per_x(*p1, *p2, win);
	draw_3d_point(p2, win);
}
