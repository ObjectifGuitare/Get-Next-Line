/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:27:46 by sepatez           #+#    #+#             */
/*   Updated: 2023/04/15 19:46:00 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	register int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = ft_strlen(src);
	result = malloc(i + 1);
	if (!result)
		return (0x0);
	result[i] = '\0';
	while (--i >= 0)
		result[i] = src[i];
	return (result);
}

int	find_br(char *line)
{
	register int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		return (i + 1);
	return (-1);
}

char	*end(char **post_line, char *buffer)
{
	char	*result;

	if (!buffer)
	{
		free(*post_line);
		*post_line = 0x0;
		return (0x0);
	}
	free(buffer);
	if (!(*post_line))
		return (0x0);
	if ((**post_line))
		return (ft_substr(post_line, find_br(*post_line)));
	result = 0x0;
	free(*post_line);
	*post_line = 0x0;
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*post_line;
	int			red;
	int			br;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (end(&post_line, 0x0));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (end(&post_line, buffer));
	br = find_br(post_line);
	while (br == -1)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red <= 0)
			return (end(&post_line, buffer));
		buffer[red] = 0;
		post_line = join_free_s1(post_line, buffer);
		br = find_br(post_line);
	}
	free(buffer);
	return (ft_substr(&post_line, br));
}

// #include <fcntl.h>
// int main()
// {
// 	int fd = open("./uke", O_RDONLY);
// 	char *s;
// 	for (int i = 0; i < 6; i++)
// 	{
// 		s = get_next_line(fd);
// 		printf("MY LINE IS : |%s|\n", s);
// 		printf(" _________\n");
// 		free(s);
// 	}
// 	close(fd);
// }

// I have to check if bugged mallocs send everything to free