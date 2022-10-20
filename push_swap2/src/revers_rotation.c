/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:45:28 by gulee             #+#    #+#             */
/*   Updated: 2022/07/16 23:57:51 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *stack_a)
{
	if (revers_rotation(stack_a) == FALSE_E)
		return (FALSE_E);
	write(1, "rra\n", 4);
	return (TRUE_E);
}

int	rrb(t_stack *stack_b)
{
	if (revers_rotation(stack_b) == FALSE_E)
		return (FALSE_E);
	write(1, "rrb\n", 4);
	return (TRUE_E);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (revers_rotation(stack_a) == FALSE_E \
	|| revers_rotation(stack_b) == FALSE_E)
		return (FALSE_E);
	write(1, "rrr\n", 4);
	return (TRUE_E);
}
