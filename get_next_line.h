/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhuwu <zhuwu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:12:00 by zhuwu             #+#    #+#             */
/*   Updated: 2025/11/08 15:52:43 by zhuwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
# define	BUFFER_SIZE

#include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

#endif