/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 06:24:57 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 06:33:35 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub3d(t_table *table)
{
	table->cub = NULL;
	table->screen_w = 1024;
	table->screen_h = 1024;
	table->x = 0;
	new_window(table);
	table->img.ptr = mlx_new_image(table->mlx, table->screen_w, \
					table->screen_h);
	table->img.arr = (int *)mlx_get_data_addr(table->img.ptr, \
					&(table->img.bpp), &(table->img.len), &(table->img.endian));
}
