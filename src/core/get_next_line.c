/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:54:45 by boksuz            #+#    #+#             */
/*   Updated: 2025/09/11 00:42:00 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *s;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = gnl_read(fd, s);
	if (!s || s[0] == '\0')
		return (free(s), s = NULL, NULL);
	line = gnl_get_line(s);
	s = gnl_trim_stash(s);
	return (line);
}
