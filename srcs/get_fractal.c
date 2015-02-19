/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 12:07:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/16 14:54:29 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fractal	get_fractal(char *str)
{
	if (!ft_strcmp(str, "julia"))
		return (JULIA);
	if (!ft_strcmp(str, "mandelbrot"))
		return (MANDELBROT);
	if (!ft_strcmp(str, "burning"))
		return (BURNING_SHIP);
	fdf_error("Invalid fractal.");
	return (IDFK);
}
