/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fdf_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 11:32:48 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/16 14:51:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_fdf_img(t_fdf_win *win)
{
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->img_bits_per_pixel = 0;
	win->img_size_line = 0;
	win->img_endian = 0;
	win->img_data = (int *)mlx_get_data_addr(win->img,
									&(win->img_bits_per_pixel),
									&(win->img_size_line),
									&(win->img_endian));
	ft_putstr("img_bits_per_pixel: ");
	ft_putnbr(win->img_bits_per_pixel);
	write(1, "\n", 1);
	ft_putstr("img_endian: ");
	ft_putnbr(win->img_endian);
	write(1, "\n", 1);
	ft_putstr("img_size_line: ");
	ft_putnbr(win->img_size_line);
	write(1, "\n", 1);
}
