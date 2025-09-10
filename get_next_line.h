/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:33:56 by boksuz            #+#    #+#             */
/*   Updated: 2025/09/10 22:33:56 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 61
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*gnl_read(int fd, char *stash);
char	*gnl_get_line(char *stash);
char	*gnl_trim_stash(char *stash);

size_t	ft_strlen(const char *str);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
