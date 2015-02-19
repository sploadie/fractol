/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_default_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 18:31:04 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/19 11:40:19 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_frac_cam	*gen_default_camera(void)
{
	t_frac_cam	*neocam;

	neocam = check_malloc(malloc(sizeof(t_frac_cam)));
	neocam->x = 0;
	neocam->y = 0;
	neocam->mouse_x = 0;
	neocam->mouse_y = 0;
	neocam->julia_x = 0;
	neocam->julia_y = 0;
	neocam->epsilon = DEF_EPSILON;
	neocam->depth = DEF_DEPTH;
	neocam->gradient = 0;
	return (neocam);
}
