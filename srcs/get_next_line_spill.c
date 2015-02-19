/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_spill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:33:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/06 12:54:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_spill	*get_next_line_spill(t_spill **new_spill)
{
	static t_spill	*spill = NULL;

	if (!new_spill)
		return (spill);
	spill = *new_spill;
	return (NULL);
}
