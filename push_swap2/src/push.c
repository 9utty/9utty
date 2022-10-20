/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:33:26 by gulee             #+#    #+#             */
/*   Updated: 2022/07/21 21:58:03 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_b, stack_a) == FALSE_E)
		return (FALSE_E);
	write(1, "pa\n", 3);
	return (TRUE_E);
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_a, stack_b) == FALSE_E)
		return (FALSE_E);
	write(1, "pb\n", 3);
	return (TRUE_E);
}
