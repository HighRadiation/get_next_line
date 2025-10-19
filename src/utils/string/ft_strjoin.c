/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:12 by boksuz            #+#    #+#             */
/*   Updated: 2025/09/11 00:48:44 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t len1;
	size_t len2;
	char *joined;
	size_t i;
	size_t j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!joined)
		return (NULL);
	i = -1;
	while (++i < len1)
		joined[i] = s1[i];
	j = -1;
	while (++j < len2)
		joined[i + j] = s2[j];
	return (joined);
}
