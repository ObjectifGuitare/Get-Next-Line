/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:27:51 by sepatez           #+#    #+#             */
/*   Updated: 2023/04/15 19:46:10 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = ft_strlen(dest);
	while (*src)
	{
		dest[i++] = *src;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*join_free_s1(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	// check result malloc and strdup
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0x0);
	result[0] = 0;
	ft_strcat(result, (char *)s1);
	free(s1);
	return (ft_strcat(result, (char *)s2));
}

int	count_me_daddy(char *s, size_t len)
{
	register int	count;

	count = 0;
	while (s[count] && len--)
		count++;
	return (count + 1);
}

char	*erase_until_br(char *post_line, int start)
{
	register int	i;
	char			*pure;

	i = 0;
	pure = malloc(ft_strlen((post_line) + start) + 1);
	if (!pure)
	{
		free((post_line));
		return (0x0);
	}
	while ((post_line)[start])
	{
		pure[i++] = (post_line)[start++];
	}
	pure[i] = 0;
	free((post_line));
	return (pure);
}

char	*ft_substr(char **post_line, int len)
{
	char	*result;
	int		i;

	if (!(*post_line))
		return (0x0);
	i = 0;
	result = malloc(count_me_daddy((*post_line), len));
	if (!result)
	{
		free(*post_line);
		return (0x0);
	}
	if (!((*post_line)[i]))
	{
		*result = 0;
		return (result);
	}
	i = -1;
	while ((*post_line)[++i] && len--)
		result[i] = (*post_line)[i];
	result[i] = 0;
	*post_line = erase_until_br(*post_line, i);
	if (!(*post_line))
		return (0x0);
	return (result);
}
