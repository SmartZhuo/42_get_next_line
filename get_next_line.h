/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhuwu <zhuwu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:12:00 by zhuwu             #+#    #+#             */
/*   Updated: 2025/10/26 14:14:13 by zhuwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
char    *ft_free(char *buffer, char *buf);
char    *ft_read(int fd, char *res);
char    *ft_get_line(char *buffer);
char    *ft_new_buffer(char *buffer);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strchr(const char *string, int searchedChar);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t elementCount, size_t elementSize);
size_t  ft_strlen(const char *theString);

#endif
