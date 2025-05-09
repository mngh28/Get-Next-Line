/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:27:14 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/05/09 17:27:18 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif
# include "unistd.h"
# include "stdlib.h"
# include <limits.h>
# include <fcntl.h>//
# include <stdio.h>//

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*read_until_newline(int fd, char *lt);
char	*extract_line(char *sv);
char	*update_left(char *sv);
char	*get_next_line(int fd);
#endif
