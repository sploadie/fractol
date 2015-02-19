/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_3d_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 12:09:47 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 10:37:20 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d_point	*new_3d_point(int x, int y, int z)
{
	t_3d_point	*neopoint;

	neopoint = check_malloc(malloc(sizeof(t_3d_point)));
	neopoint->x = x;
	neopoint->y = y;
	neopoint->z = z;
	return (neopoint);
}
