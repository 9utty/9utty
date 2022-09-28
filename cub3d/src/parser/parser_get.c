/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:25:10 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 08:26:06 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_map(t_table *table)
{
	char	**buff;
	int		index;

	index = 0;
	while (index < 4)
	{
		buff = ft_split(table->cub[index++], ", \n");
	}
}
