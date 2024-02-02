/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro < treis-ro@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:02:45 by treis-ro          #+#    #+#             */
/*   Updated: 2024/02/02 14:21:38 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
	static char     follow_read[FOPEN_MAX][BUFFER_SIZE + 1];
	char            *line;
	int             i;
	
	line = NULL;
	i = 0;
	if (read(fd, 0, 0) < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
	{
		if (fd >= 0  && fd < FOPEN_MAX)
		{
			while (i <= BUFFER_SIZE)
				follow_read[fd][i++] = '\0';
		}
		return (NULL);
	}
	while (follow_read[fd][0] || read(fd, follow_read[fd], BUFFER_SIZE) > 0)
	{
		line = gnl_strjoin(line, follow_read[fd]);
		if (!line)
			return (NULL);
		gnl_update(follow_read[fd]);
		if (line[gnl_strlen(line) - 1] == '\n')
			return (line);
	}
	return (line);
}
