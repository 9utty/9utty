/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:28:52 by gulee             #+#    #+#             */
/*   Updated: 2022/07/21 22:30:54 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_top(t_stack *stack)
{
	return (stack->table[stack->len - 1]);
}

int	stack_bottom(t_stack *stack)
{
	return (stack->table[0]);
}
