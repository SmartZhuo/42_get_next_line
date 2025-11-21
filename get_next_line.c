/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhuwu <zhuwu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:11:57 by zhuwu             #+#    #+#             */
/*   Updated: 2025/10/26 14:16:18 by zhuwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// join and free
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char  *ft_read(int fd, char *res)
{
    char *buffer;
    int flag;
    char *tmp;

    if(!res)
      res = ft_calloc(1, 1);
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    flag = 1;
    while(flag > 0)
    {
        flag = read(fd, buffer, BUFFER_SIZE);
        if (flag == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[flag] = '\0';
        res = ft_free(res, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (res);
}

char *ft_get_line(char *buffer)
{
    char *line;
    size_t i;

    if(!buffer)
        return (NULL);
    if(buffer[0] == '\0')
        return (NULL);
    i = 0;
    while(buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    line = ft_calloc(i+ 2, sizeof(char));
    i = 0;
    while(buffer[i] != '\0' && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';   
    return (line);
}

char *ft_new_buffer(char *buffer)
{
    char *new_buffer;
    size_t i;
    size_t j;

    if(!buffer)
        return (NULL);
    if(buffer[0] == '\0')
        return (NULL);

    i = 0;
    while(buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    if(buffer[i] == '\0')
    {
        free(buffer);
        return (NULL);
    }
    i++;
    new_buffer = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
    if (!new_buffer)
        return (NULL);
    j = 0;
    while(buffer[i] != '\0')
        new_buffer[j++] = buffer[i++];   
    new_buffer[j] = '\0';
    free(buffer);
    return (new_buffer);
}


char	*get_next_line(int fd)
{
    char        *line;
    static char *buffer; 
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    //读取文件，把内容补到buffer中
    buffer = ft_read(fd, buffer);
    if (!buffer)
        return (NULL);
    // 从buffer中读取一行 包括/0
    line = ft_get_line(buffer);
    // 删除已取出的那行，保留剩余部分
    buffer = ft_new_buffer(buffer);
    return (line);
}
