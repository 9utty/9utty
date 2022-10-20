/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:40:31 by gulee             #+#    #+#             */
/*   Updated: 2022/07/25 19:13:14 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *to, t_stack *from)
{
	int	tmp_value;

	if (to->len == 0)
		return (FALSE_E);
	tmp_value = to->table[to->len - 1];
	if (is_empty(to))
	{
		to->len -= 1;
		from->table[from->len] = tmp_value;
		from->len += 1;
	}
	return (TRUE_E);
}

int	rotation(t_stack *stack)
{
	int	tmp_value;
	int	index;

	if (stack->len <= 1)
		return (FALSE_E);
	index = stack->len -1 ;
	tmp_value = stack->table[stack->len - 1];
	while (index > 0)
	{
		stack->table[index] = stack->table[index - 1];
		--index;
	}
	stack->table[0] = tmp_value;
	return (TRUE_E);
}

int	swap(t_stack *stack)
{
	int		tmp_value;

	if (stack->len < 2)
		return (FALSE_E);
	tmp_value = stack->table[stack->len - 1];
	stack->table[stack->len - 1] = stack->table[stack->len - 2];
	stack->table[stack->len - 2] = tmp_value;
	return (TRUE_E);
}

int	revers_rotation(t_stack *stack)
{
	int	tmp_value;
	int	index;

	index = 0;
	tmp_value = stack->table[0];
	if (stack->len < 2)
		return (FALSE_E);
	while (index < stack->len - 1)
	{
		stack->table[index] = stack->table[index + 1];
		++index;
	}
	stack->table[stack->len - 1] = tmp_value;
	return (TRUE_E);
}
