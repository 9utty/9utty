/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:00:28 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 03:10:48 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_b(t_stack *b, t_stack *a, int size)
{
	b->table = malloc(sizeof(int) * size);
	if (!b->table)
	{
		free(a->table);
		push_swap_error(NULL);
	}
	b->len = 0;
	b->size = size;
}

void	set_stack_a(t_stack *a, int num)
{
	int	*tmp;
	int	index;

	index = a->len;
	tmp = NULL;
	if (a->len >= a->size)
	{
		tmp = malloc(sizeof(int) * (a->size << 1));
		if (!tmp)
			push_swap_error(NULL);
		ft_memcpy(tmp, a->table, (a->len * sizeof(int)));
		free(a->table);
		a->table = tmp;
		a->size <<= 1;
	}
	while (index > 0)
	{
		a->table[index] = a->table[index - 1];
		--index;
	}
	a->table[0] = num;
	a->len += 1;
}
