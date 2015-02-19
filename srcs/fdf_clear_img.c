/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clear_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 10:34:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 10:31:59 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clear_img(t_fdf_win *win)
{
	size_t		i;
	size_t		j;
	size_t		width;
	size_t		height;

	width = win->width;
	height = win->height;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			win->img_data[(i * width) + (j++)] = 0x000000;
		i++;
	}
}
