/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_point_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:13:08 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 10:25:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map_point_lines(size_t x, size_t y, t_fdf_map *map, t_fdf_win *win)
{
	if (x < map->width - 1)
		draw_point_line(map->grid[y][x], map->grid[y][x + 1], win);
	if (y < map->height - 1)
		draw_point_line(map->grid[y][x], map->grid[y + 1][x], win);
}
