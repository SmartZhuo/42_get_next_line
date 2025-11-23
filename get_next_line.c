/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhuwu <zhuwu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:17:15 by zhuwu             #+#    #+#             */
/*   Updated: 2025/11/23 12:21:47 by zhuwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*rest;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	rest = NULL;
	if (buffer[0] != '\0')
	{
		rest = ft_strdup(buffer);
		if(!rest)
			return (NULL);
	}
	rest = ft_read(fd, rest);
	if(!rest)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	line = ft_get_line(&rest);
	ft_buffer(buffer, &rest);
	return (line);
}

char	*ft_read(int fd, char *rest)
{
	char	*tmp;
	int		flag;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(rest);
		return(NULL);
	}
	flag = 1;
	while(!ft_strchr(rest, '\n' && flag != 0))
	{
		flag = read(fd, tmp, BUFFER_SIZE);
		if (flag < 0)
		{
			free(tmp);
			free(rest);
			return (NULL);
		}
		if (flag == 0)
			break;
		tmp[flag] = '\0';
		rest = ft_strjoin(rest, tmp);
		if (!rest)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (rest);
}


https://github.com/eskomo04/get_next_line/blob/master/get_next_line.c