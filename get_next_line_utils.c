/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:43:18 by rrakotos          #+#    #+#             */
/*   Updated: 2024/03/20 09:37:12 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*memory;
	size_t	total_size;
	size_t	i;

	total_size = elementCount * elementSize;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((char *)memory)[i] = 0;
		i++;
	}
	return (memory);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	char	*tmp_s1;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_s = ft_calloc((len + 1), 1);
	if (!new_s)
		return (free(s1), NULL);
	tmp_s1 = s1;
	while (*tmp_s1)
		*(new_s++) = *(tmp_s1++);
	while (*s2)
		*(new_s++) = *(s2++);
	free(s1);
	return (new_s - len);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}
