/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:00:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/08 23:56:52 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *leftover)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(leftover, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(leftover);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		if (!leftover)
			leftover = ft_strdup("");
		if (!leftover)
		{
			free(buffer);
			return (NULL);
		}
		temp = leftover;
		leftover = ft_strjoin(leftover, buffer);
		free(temp);
		if (!leftover)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (leftover);
}

static char	*extract_line(char *leftover)
{
	char	*line;
	size_t	i;

	if (!leftover || leftover[0] == '\0')
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	line = ft_substr(leftover, 0, i);
	return (line);
}

static char	*update_leftover(char *leftover)
{
	char	*new_leftover;
	size_t	i;
	size_t	len;

	if (!leftover)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\0')
	{
		free(leftover);
		return (NULL);
	}
	len = ft_strlen(leftover);
	new_leftover = ft_substr(leftover, i + 1, len - i - 1);
	free(leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	leftover[fd] = read_buffer(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	line = extract_line(leftover[fd]);
	leftover[fd] = update_leftover(leftover[fd]);
	return (line);
}

