/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:27:49 by sepatez           #+#    #+#             */
/*   Updated: 2023/04/15 19:36:10 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strcat(char *dest, char *src);
char	*join_free_s1(char *s1, char *s2);
char	*ft_substr(char **s, int len);
char	*ft_strdup(char *src);
int		count_me_daddy(char *s, size_t len);
int		ft_strlen( char *s);
char	*erase_until_br(char *post_line, int start);
char	*end(char **post_line, char *buffer);

#endif