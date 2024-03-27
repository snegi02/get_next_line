/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:21:44 by snegi             #+#    #+#             */
/*   Updated: 2023/12/13 13:22:18 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*findline(char *res)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!res)
		return (NULL);
	while (res[i] != '\n' && res[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (res[i] != '\n' && res[i] != '\0')
	{
		line[i] = res[i];
		i++;
	}
	line[i] = res[i];
	line[++i] = '\0';
	return (line);
}

char	*readfile(int fd, char *res, char *buf)
{
	ssize_t	char_read;
	char	*temp;

	if (!buf)
		return (NULL);
	char_read = read(fd, buf, BUFFER_SIZE);
	while (char_read > 0 && buf[0] != '\0')
	{
		buf[char_read] = '\0';
		temp = res;
		res = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			return (res);
		else
			char_read = read(fd, buf, BUFFER_SIZE);
	}
	if (char_read < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*final(char *res, char *temp, char *line)
{
	size_t		i;
	size_t		j;

	i = 0;
	i = ft_strlen(line);
	res = malloc(((ft_strlen(temp) - i) + 1) * sizeof(char));
	j = 0;
	while (temp[i] != '\0')
		res[j++] = temp[i++];
	res[j] = '\0';
	free(temp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res[1024];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(res[fd]);
		res[fd] = NULL;
		return (NULL);
	}
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	temp = readfile(fd, res[fd], line);
	free(line);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free(temp);
		res[fd] = NULL;
		return (NULL);
	}
	line = findline(temp);
	res[fd] = final(res[fd], temp, line);
	return (line);
}
