/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:10:08 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 03:01:52 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_error(t_stack *stack)
{
	int	*tmp;

	write(2, "Error\n", 6);
	if (stack == NULL)
		exit(0);
	else
	{
		tmp = stack->table;
		free(tmp);
		tmp = NULL;
	}
	stack->table = NULL;
	exit(0);
}
