/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:34:59 by crepou            #+#    #+#             */
/*   Updated: 2023/11/08 18:11:19 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"

void	print(char *string)
{
	printf("%s", string);
}

void	print_s(char *string, char *argument)
{
	while (*string)
	{
		if (*string != '%')
			printf("%c", *string);
		else
			break ;
		string++;
	}
	printf("%s", argument);
	string += 2;
	while (*string)
	{
		printf("%c", *string);
		string++;
	}
}

void	print_mixed(char *string, char *argument, int argument2)
{
	while (*string)
	{
		if (*string != '%')
			printf("%c", *string);
		else
			break ;
		string++;
	}
	printf("%s", argument);
	string += 2;
	while (*string)
	{
		if (*string != '%')
			printf("%c", *string);
		else
			break ;
		string++;
	}
	printf("%c ", argument2);
	string += 2;
	while (*string)
	{
		printf("%c", *string);
		string++;
	}
}
