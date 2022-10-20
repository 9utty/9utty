/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:37:01 by gulee             #+#    #+#             */
/*   Updated: 2022/07/25 21:09:42 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ra(t_stack *stack_a)
{
	if (rotation(stack_a) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}

int	rb(t_stack *stack_b)
{
	if (rotation(stack_b) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (rotation(stack_a) == FALSE_E || rotation(stack_b) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}
