/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:27:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/02 19:26:36 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_file_height(char *path)
{
	int				fd;
	int				ret;
	char			buf[BUF_SIZE + 1];
	char			*s;
	size_t			count;

	if ((fd = open(path, O_RDONLY)) == -1)
		fdf_error("get_file_height");
	count = 0;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		s = buf;
		while (*s != '\0')
		{
			if (*s == '\n')
				count++;
			s++;
		}
	}
	if (ret != 0)
		fdf_error("get_file_height");
	close(fd);
	return (count);
}
