/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:21:50 by rrakotos          #+#    #+#             */
/*   Updated: 2024/03/20 12:22:46 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*memory[FD_MAX];
	char		*buffer;

	if (fd < 0 || (BUFFER_SIZE <= 0 || fd > 1024))
		return (NULL);
	if (!memory[fd])
		memory[fd] = ft_calloc(1, sizeof(char *));
	if (!memory[fd])
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(memory[fd]), NULL);
	memory[fd] = read_fd(fd, memory[fd], buffer);
	if (!memory[fd])
		return (NULL);
	buffer = extract_line(memory[fd]);
	memory[fd] = realloc_after_line(memory[fd]);
	if (!memory[fd])
		return (free(buffer), NULL);
	return (buffer);
}

void	free_all(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*read_fd(int fd, char *storage, char *buffer)
{
	ssize_t		nread;

	nread = BUFFER_SIZE;
	while (nread == BUFFER_SIZE && !(ft_strchr(storage, '\n')))
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread < 0)
			return (free_all(buffer, storage), NULL);
		buffer[nread] = 0;
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}

char	*extract_line(char *memory)
{
	ssize_t	i;
	char	*new_line;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i = i + 1;
	new_line = ft_calloc((i + 1), sizeof(char));
	if (!new_line)
		return (free(memory), NULL);
	new_line[i] = 0;
	i--;
	while (i >= 0)
	{
		new_line[i] = memory[i];
		i--;
	}
	return (new_line);
}

char	*realloc_after_line(char *memory)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i] && i == 0)
		return (free(memory), NULL);
	new = ft_calloc((ft_strlen(memory) - i) + 1, sizeof(char));
	if (!new)
		return (free(memory), NULL);
	j = 0;
	i += (memory[i] == '\n');
	while (memory[i])
	{
		new[j] = memory[i];
		j++;
		i++;
	}
	free(memory);
	return (new);
}
