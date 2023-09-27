/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:07:50 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/27 16:55:07 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	single_key_h(mlx_key_data_t keydata, void *param)
{
	t_displ	*s_displ;

	s_displ = (t_displ *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(s_displ->window);
		return ;
	}
}