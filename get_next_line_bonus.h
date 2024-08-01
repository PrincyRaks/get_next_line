/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:00 by rrakotos          #+#    #+#             */
/*   Updated: 2024/03/20 12:04:36 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

void	*ft_calloc(size_t elementCount, size_t elementSize);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*read_fd(int fd, char *storage, char *buffer);
char	*extract_line(char *buffer);
char	*realloc_after_line(char *memory);
void	free_all(char *s1, char *s2);

#endif
