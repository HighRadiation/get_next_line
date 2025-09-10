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

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = gnl_read(fd, s);
	if (!s || s[0] == '\0')
		return (free(s), s = NULL, NULL);
	line = gnl_get_line(s);
	s = gnl_trim_stash(s);
	return (line);
}

char	*gnl_read(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	ssize_t	rd;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	rd = 1;
	if (!stash)
		stash = ft_calloc(1, 1);
	while (!ft_strchr(stash, '\n') && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[rd] = '\0';
		tmp = ft_strjoin(stash, buf);
		free(stash);
		stash = tmp;
	}
	return (free(buf), stash);
}

char	*gnl_get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*gnl_trim_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
