/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:24:30 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 12:30:56 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorting_3(t_stack *a)
{
	if (a->table[0] > a->table[1] && a->table[1] < a->table[2] && \
		a->table[2] < a->table[0])
		order_sort(a, NULL, SA_E);
	else if (a->table[0] < a->table[1] & a->table[1] < a->table[2] && \
		a->table[2] > a->table[0])
	{
		order_sort(a, NULL, SA_E);
		order_sort(a, NULL, RRA_E);
	}
	else if (a->table[0] > a->table[1] && a->table[1] < a->table[2] && \
		a->table[2] > a->table[0])
		order_sort(a, NULL, RA_E);
	else if (a->table[0] < a->table[1] && a->table[1] > a->table[2] && \
		a->table[2] < a->table[0])
	{
		order_sort(a, NULL, SA_E);
		order_sort(a, NULL, RA_E);
	}
	else if (a->table[0] < a->table[1] && a->table[1] > a->table[2] && \
		a->table[2] > a->table[0])
		order_sort(a, NULL, RRA_E);
}

static int	get_mid(t_stack *a)
{
	int	index;
	int	tmp_index;
	int	point;

	index = 0;
	while (index < a->len)
	{
		tmp_index = 0;
		point = 0;
		while (tmp_index < a->len)
		{
			if (a->table[tmp_index] - a->table[index] > 0)
				++point;
			++tmp_index;
		}
		if (point == 2)
			return (a->table[index]);
		++index;
	}
	return (1);
}

void	small_sorting(t_stack *a, t_stack *b)
{
	if (is_sorted(a) || a->len == 0 || a->len == 1)
		return ;
	while (3 < a->len)
	{
		while (stack_top(a) >= get_mid(a))
			order_sort(a, b, RA_E);
		order_sort(a, b, PB_E);
	}
	if (a->len == 3)
		sorting_3(a);
	while (b->len > 0)
		order_sort(a, b, PA_E);
	if (a->len == 2 || stack_top(a) > a->table[a->len - 2])
		order_sort(a, b, SA_E);
}
