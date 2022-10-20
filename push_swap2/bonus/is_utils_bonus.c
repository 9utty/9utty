/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:59:22 by gulee             #+#    #+#             */
/*   Updated: 2022/07/27 18:23:26 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_empty(t_stack *stack)
{
	if (stack->len > 0)
		return (TRUE_E);
	return (FALSE_E);
}

int	argv_empty(char **argv)
{
	int	index;

	index = 0;
	while (argv[index])
	{
		if (argv[index][0] == '\0')
			return (FALSE_E);
		++index;
	}
	return (TRUE_E);
}

int	is_sorted(t_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->len - 1)
	{
		if (stack->table[index] < stack->table[index + 1])
			return (FALSE_E);
		++index;
	}
	return (TRUE_E);
}
