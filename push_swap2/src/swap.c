/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:02:33 by gulee             #+#    #+#             */
/*   Updated: 2022/07/16 23:57:05 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack_a)
{
	if (swap(stack_a) == FALSE_E)
		return (FALSE_E);
	write(1, "sa\n", 3);
	return (TRUE_E);
}

int	sb(t_stack *stack_b)
{
	if (swap(stack_b) == FALSE_E)
		return (FALSE_E);
	write(1, "sb\n", 3);
	return (TRUE_E);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (swap(stack_a) == FALSE_E || swap(stack_b) == FALSE_E)
		return (FALSE_E);
	write(1, "ss\n", 3);
	return (TRUE_E);
}
