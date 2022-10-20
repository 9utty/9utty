/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:03:01 by gulee             #+#    #+#             */
/*   Updated: 2022/07/01 01:07:31 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_exit_img(t_data *data)
{
	if (data->map[data->exit_y][data->exit_x] == 'E')
	{
		put_img(data, data->img_exit, data->exit_x, data->exit_y);
	}
}

void	put_img(t_data *data, void *img_value, int x, int y)
{
	mlx_put_image_to_window(data->mlx, \
	data->window, img_value, x * 64, y * 64);
}

void	put_player_img(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, \
	data->window, data->img_player, x * 64, y * 64);
	data->player_x = x;
	data->player_y = y;
}
