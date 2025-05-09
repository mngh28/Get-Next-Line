/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:18:07 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/04/16 14:23:35 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 28
# endif
# include "unistd.h"
# include "stdlib.h"
#include <fcntl.h>//
#include <stdio.h>//

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst1, const char *src, size_t dstsize);
char	*read_until_newline(int fd, char *lt);
char	*extract_line(char *sv);
char	*update_left(char *sv);
char	*get_next_line(int fd);
#endif
