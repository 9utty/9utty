/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:39:25 by gulee             #+#    #+#             */
/*   Updated: 2022/07/25 20:40:30 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	make_index(t_stack *a)
{
	int	*tmp_arr;
	int	index;
	int	tmp_index;

	index = 0;
	tmp_arr = malloc(sizeof(int) * a->len);
	if (tmp_arr == NULL)
		push_swap_error(a);
	while (index < a->len)
	{
		tmp_index = 0;
		tmp_arr[index] = 0;
		while (tmp_index < a->len)
		{
			if (a->table[index] > a->table[tmp_index])
				tmp_arr[index] += 1;
			++tmp_index;
		}
		++index;
	}
	free(a->table);
	a->table = NULL;
	a->table = tmp_arr;
}
