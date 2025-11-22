/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhuwu <zhuwu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:11:57 by zhuwu             #+#    #+#             */
/*   Updated: 2025/11/22 20:09:07 by zhuwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_new_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read(int fd, char *res)
{
	char	*buffer;
	int		flag;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	flag = 1;
	while (flag > 0)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
	{
		buffer = NULL;
		return (NULL);
	}
	line = ft_get_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (line);
}

# include <fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include "get_next_line.h"

int main()
{
	int fd;
	char *line;

	fd = open("test.txt",O_RDONLY);
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s",line);
		free(line);
	}
	close(fd);
	return (0);
}
