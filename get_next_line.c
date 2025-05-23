/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:08:42 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/04/16 14:16:52 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_newline(int fd, char *buffer)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (i != 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (free(buf), free(buffer), buffer = NULL, NULL);
		buf[i] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	size_t	i;
	char	*ugh;

	ugh = NULL;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	ugh = ft_substr(buffer, 0, i + 1);
	return (ugh);
}

char	*update_left(char *buffer)
{
	size_t	start;
	char	*tmp;

	start = 0;
	tmp = NULL;
	if (!buffer)
		return (NULL);
	while (buffer[start] && buffer[start] != '\n')
		start++;
	if (!buffer[start])
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_substr(buffer, start + 1, ft_strlen(buffer) - start);
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL);
	buffer = read_until_newline(fd, buffer);
	line = extract_line(buffer);
	buffer = update_left(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	// int fd2;
// 	fd = open("alo.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		get_next_line(-1);
//  }
