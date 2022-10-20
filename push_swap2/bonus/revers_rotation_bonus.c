/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rotation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:45:28 by gulee             #+#    #+#             */
/*   Updated: 2022/07/25 21:15:22 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rra(t_stack *stack_a)
{
	if (revers_rotation(stack_a) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}

int	rrb(t_stack *stack_b)
{
	if (revers_rotation(stack_b) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (revers_rotation(stack_a) == FALSE_E \
	|| revers_rotation(stack_b) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}
