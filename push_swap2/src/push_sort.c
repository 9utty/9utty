/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:41:48 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 14:48:07 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap_gogo(t_stack *a, t_stack *b, int pivot)
{
	int	index;

	index = 0;
	while (is_empty(a))
	{
		if (stack_top(a) <= index)
		{
			order_sort(a, b, PB_E);
			++index;
		}
		else if (index < stack_top(a) && stack_top(a) <= index + pivot)
		{
			order_sort(a, b, PB_E);
			order_sort(a, b, RB_E);
			++index;
		}
		else if (index + pivot < stack_top(a))
			order_sort(a, b, RA_E);
	}
}

static void	revers_push_swap_gogo(t_stack *a, t_stack *b, int pivot)
{
	int	index;

	index = 0;
	while (is_empty(a))
	{
		if (stack_top(a) <= index)
		{
			order_sort(a, b, PB_E);
			++index;
		}
		else if (index < stack_top(a) && stack_top(a) <= index + pivot)
		{
			order_sort(a, b, PB_E);
			order_sort(a, b, RB_E);
			++index;
		}
		else if (index + pivot < stack_top(a))
			order_sort(a, b, RRA_E);
	}
}

static void	to_b_from_a(t_stack *a, t_stack *b)
{
	int	index;
	int	tmp_index;

	index = b->len - 1;
	while (is_empty(b))
	{
		tmp_index = 0;
		while (tmp_index < b->len && b->table[tmp_index] != index)
			++tmp_index;
		while (tmp_index < b->len / 2 && tmp_index >= 0)
		{
			order_sort(NULL, b, RRB_E);
			--tmp_index;
		}
		while (tmp_index >= b->len / 2 && tmp_index < b->len - 1)
		{
			order_sort(NULL, b, RB_E);
			++tmp_index;
		}
		order_sort(a, b, PA_E);
		--index;
	}
}

void	push_sort(t_stack *a, t_stack *b)
{
	int		pivot;
	int		tmp;
	double	alpha;
	double	beta;

	alpha = 5.29427309e-7;
	beta = 0.024;
	pivot = (alpha * (a->len * a->len)) + (beta * (a->len)) + 15;
	tmp = sort_check(a);
	if (tmp == FALSE_E)
		revers_push_swap_gogo(a, b, pivot);
	else if (tmp == TRUE_E)
		push_swap_gogo(a, b, pivot);
	to_b_from_a(a, b);
}
