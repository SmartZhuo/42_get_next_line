/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhuwu <zhuwu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:11:57 by zhuwu             #+#    #+#             */
/*   Updated: 2025/11/08 19:55:07 by zhuwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left_str;
	char	*buf;
	int		bytes;
	char	*flag;
	
	left_str = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0|| BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(left_str, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		else if (bytes == 0)
			break;
		left_str = ft_strjoin(left_str, buf);
	}
	if (!left_str)
	{
		
	}

}
	
	
	
	
}