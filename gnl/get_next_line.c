/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:02 by crepou            #+#    #+#             */
/*   Updated: 2023/03/21 19:36:54 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	char	*p;

	if (!str)
		return (NULL);
	p = (char *)str;
	while (str++)
	{
		if (*p == (char )c)
			return (p);
		if (!*p)
			return (0);
		p++;
	}
	if (*p == (char)c)
		return (p);
	return (0);
}

char	*final_str(char *left, int *count)
{
	char	*ret_str;
	int		i;

	while (left[*count] != '\n' && left[*count] != '\0')
		(*count)++;
	if (left[*count] == '\n')
		(*count)++;
	ret_str = (char *)malloc(*count);
	if (!ret_str)
		return (NULL);
	i = 0;
	while (i < *count)
	{
		ret_str[i] = left[i];
		i++;
	}
	return (ret_str);
}

char	*create_left( char *buf, int fd, char *left)
{
	int		retval;

	retval = 1;
	while (retval != 0 && !ft_strchr(left, '\n'))
	{
		retval = read(fd, buf, BUFFER_SIZE);
		if (retval == -1)
		{
			free(left);
			return (NULL);
		}
		buf[retval] = '\0';
		left = ft_strjoin_gnl(left, buf);
	}
	return (left);
}

char	*create_final(char **left)
{
	int			size;
	char		*final;
	char		*ptr;

	ptr = *left;
	size = ft_strchr(*left, '\n') - ptr + 1;
	final = ft_substr_gnl(ptr, 0, size);
	*left = ft_substr_gnl(ptr, size, ft_strlen_gnl(ptr) - size + 1);
	free(ptr);
	return (final);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*left;
	char		*final;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	final = NULL;
	left = create_left(buf, fd, left);
	if (left && *left != '\0')
		final = create_final(&left);
	free(buf);
	return (final);
}
