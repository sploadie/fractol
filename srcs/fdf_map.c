/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:01:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/02 19:11:03 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_3d_point	***fdf_map_grid(size_t width, size_t height)
{
	size_t		i;
	size_t		j;
	t_3d_point	***grid;

	grid = check_malloc(malloc(sizeof(t_3d_point**) * height));
	i = 0;
	while (i < height)
	{
		grid[i] = check_malloc(malloc(sizeof(t_3d_point*) * width));
		j = 0;
		while (j < width)
			grid[i][j++] = new_3d_point(0, 0, 0);
		i++;
	}
	return (grid);
}

t_fdf_map			*fdf_map(size_t width, size_t height)
{
	t_fdf_map	*map;

	map = check_malloc(malloc(sizeof(t_fdf_map)));
	map->width = width;
	map->height = height;
	map->grid = fdf_map_grid(width, height);
	return (map);
}
