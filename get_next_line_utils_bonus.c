/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:23:00 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/05/09 17:23:07 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		l++;
		str++;
	}
	return (l);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)s;
	while (*p && *p != (char)c)
		p++;
	if (*p == (char)c)
		return ((char *)p);
	return (NULL);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s) - start;
	if (len < i)
		i = len;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	j = 0;
	while (j < len && s[start])
	{
		p[j] = s[start];
		j++;
		start++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strdup(const char *src)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)malloc(ft_strlen(src) + 1);
	if (s1 == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		s1[i] = src[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
