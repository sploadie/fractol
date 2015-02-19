/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_fdf_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:05:59 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 10:40:54 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trans_fdf_map(t_fdf_map *dest, t_fdf_map *src, t_fdf_cam *cam)
{
	t_3d_point	***grid;
	size_t		i;
	size_t		j;
	size_t		width;
	size_t		height;

	width = src->width;
	height = src->height;
	grid = dest->grid;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			trans_3d_point(grid[i][j], src->grid[i][j], cam);
	}
	dest->width = width;
	dest->height = height;
	dest->grid = grid;
}
