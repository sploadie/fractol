/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 13:54:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/02 18:55:36 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*check_malloc(void *ret)
{
	if (ret)
		return (ret);
	fdf_error(NULL);
	return (NULL);
}
