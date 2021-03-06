/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:32:06 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/07 14:14:48 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	int		rd;
	char	c;
	char	*line;
	char	*word;

	rd = 0;
	rd = read(fd, &c, 1);
	if (rd == 0)
		return (NULL);
	line = malloc(100000);
	word = line;
	*line++ = c;
	while (rd > 0 && c != '\n')
	{
		rd = read(fd, &c, 1);
		*line++ = c;
	}
	*line = '\0';
	return (word);
}

// if (c == '\n')
	// 	*line++ = '\n';