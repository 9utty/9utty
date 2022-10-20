/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:32:10 by gulee             #+#    #+#             */
/*   Updated: 2022/07/25 20:40:44 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	is_same_number(t_stack *stack)
{
	int	index;
	int	tmp_index;
	int	tmp_num;
	int	*tmp;

	tmp = stack->table;
	index = 0;
	tmp_index = 0;
	while (index < stack->len)
	{
		tmp_num = tmp[index];
		tmp_index = index + 1;
		while (tmp_index < stack->len)
		{
			if (tmp_num == tmp[tmp_index])
				push_swap_error(stack);
			++tmp_index;
		}
		++index;
	}
}
