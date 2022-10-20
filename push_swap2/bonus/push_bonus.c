/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:33:26 by gulee             #+#    #+#             */
/*   Updated: 2022/07/25 21:15:48 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_b, stack_a) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_a, stack_b) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}
