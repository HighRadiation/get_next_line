/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:12 by boksuz            #+#    #+#             */
/*   Updated: 2025/09/11 00:48:44 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strdup(const char *str)
{
	char *str1;
	size_t len;
	size_t i;

	len = ft_strlen(str);
	str1 = ft_calloc(len + 1, sizeof(char));
	if ((str1) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str1[i] = str[i];
		i++;
	}
	return (str1);
}
