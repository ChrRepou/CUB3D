/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:22:20 by crepou            #+#    #+#             */
/*   Updated: 2023/03/21 19:38:51 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

char			*ft_strdup_gnl(const char *string);
size_t			ft_strlen_gnl(const char *str);
char			*ft_substr_gnl(char *s, unsigned int start, size_t len);
char			*ft_strjoin_gnl(char *s1, char const *s2);
char			*get_next_line(int fd);
#endif