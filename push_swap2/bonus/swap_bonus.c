/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:02:33 by gulee             #+#    #+#             */
/*   Updated: 2022/07/25 21:15:35 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sa(t_stack *stack_a)
{
	if (swap(stack_a) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}

int	sb(t_stack *stack_b)
{
	if (swap(stack_b) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (swap(stack_a) == FALSE_E || swap(stack_b) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}
