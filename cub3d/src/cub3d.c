/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:51:36 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 06:35:10 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_table	table;

	ft_memset(&table, 0, sizeof(t_table));
	if (ac != 2)
		err_put();
	table.mlx = mlx_init();
	if (!table.mlx)
		err_put();
	init_game(&table);
	table.map.filename = ft_strdup(av[1]);
	parser(&table);
}