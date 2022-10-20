/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:01:43 by gulee             #+#    #+#             */
/*   Updated: 2022/07/25 19:34:44 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order_swap(t_stack *a, t_stack *b, t_order_num key)
{
	if (key == SA_E)
		sa(a);
	else if (key == SB_E)
		sb(b);
	else if (key == SS_E)
		ss(a, b);
}

static void	order_push(t_stack *a, t_stack *b, t_order_num key)
{
	if (key == PA_E)
		pa(a, b);
	else if (key == PB_E)
		pb(a, b);
}

static void	order_rotation(t_stack *a, t_stack *b, t_order_num key)
{
	if (key == RA_E)
		ra(a);
	else if (key == RB_E)
		rb(b);
	else if (key == RR_E)
		rr(a, b);
}

static void	order_r_rotation(t_stack *a, t_stack *b, t_order_num key)
{
	if (key == RRA_E)
		rra(a);
	else if (key == RRB_E)
		rrb(b);
	else if (key == RRR_E)
		rrr(a, b);
}

void	order_sort(t_stack *a, t_stack *b, t_order_num key)
{
	if (key <= SS_E)
		order_swap(a, b, key);
	else if (key > SS_E && key <= PB_E)
		order_push(a, b, key);
	else if (key > PB_E && key <= RR_E)
		order_rotation(a, b, key);
	else if (key > RR_E && key <= RRR_E)
		order_r_rotation(a, b, key);
	else
	{
		free(a->table);
		free(b->table);
		push_swap_error(NULL);
		push_swap_error(NULL);
	}
}
