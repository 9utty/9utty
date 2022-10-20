/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:19:20 by gulee             #+#    #+#             */
/*   Updated: 2022/07/01 01:05:35 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_image(data->mlx, data->img_collec);
	mlx_destroy_image(data->mlx, data->img_exit);
	mlx_destroy_image(data->mlx, data->img_ground);
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_window(data->mlx, data->window);
	free_map(data->map);
	exit(0);
	return (0);
}
