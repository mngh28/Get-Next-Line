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

	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(buffer), NULL);
	i = 1;
	while (!ft_strchr(buffer, '\n') && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (free(buf), free(buffer), buffer = NULL, NULL);
		buf[i] = '\0';
		buffer = ft_strjoin(buffer, buf);
		free(buf);
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
	if (buffer[i] == '\n')
		i++;
	ugh = ft_substr(buffer, 0, i);
	return (ugh);
}

char	*update_left(char *buffer)
{
	size_t	start;
	char	*nwsv;

	start = 0;
	nwsv = NULL;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[start] && buffer[start] != '\n')
		start++;
	if (!buffer[start])
		return (NULL);
	start++;
	nwsv = ft_substr(buffer, start, ft_strlen(buffer) - start + 1);
	return (nwsv);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;


	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	buffer = read_until_newline(fd, buffer);
	if (!buffer || !*buffer)
		return (free(buffer), NULL);
	line = extract_line(buffer);
	if (!line || !*line)
		return (free(buffer), NULL);
	buffer = update_left(buffer);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	// int fd2;
	fd = open("alo.txt", O_RDONLY);
	line = get_next_line(fd);
	for (int i = 0; i < 3; ++i) {
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
 }
 