/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:33:46 by boksuz            #+#    #+#             */
/*   Updated: 2025/09/11 18:11:12 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	static char *s[4242];
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = gnl_read(fd, s[fd]);
	if (!s[fd] || s[fd][0] == '\0')
		return (free(s[fd]), s[fd] = NULL, NULL);
	line = gnl_get_line(s[fd]);
	s[fd] = gnl_trim_stash(s[fd]);
	return (line);
}
