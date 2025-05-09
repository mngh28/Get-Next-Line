/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:17:10 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/04/16 14:24:06 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*p;
	size_t	k;

	k = 0;
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (NULL);
	p[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (k <= ft_strlen(s1))
	{
		p[k] = s1[k];
		k++;
	}
	k = 0;
	while (k <= ft_strlen(s2))
	{
		p[k + ft_strlen(s1)] = s2[k];
		k++;
	}
	free(s1);
	return (p);
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
	//free(s);
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
