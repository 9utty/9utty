/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:51:32 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 15:10:46 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_check(t_stack *a, int top, int bottom)
{
	if (a->len <= 100 && top < 40)
		return (TRUE_E);
	else if (a->len <= 300 && top < 120)
		return (TRUE_E);
	else if (a->len <= 500 && top < 200)
		return (TRUE_E);
	else if (bottom < top)
		return (FALSE_E);
	else
		return (FALSE_E);
}

int	sort_check(t_stack *a)
{
	int	tmp_len;
	int	index;
	int	count_bottom;
	int	count_top;

	tmp_len = a->len / 2;
	index = 0;
	count_bottom = 0;
	count_top = 0;
	while (index < tmp_len)
	{
		if (a->table[index] > tmp_len)
			++count_bottom;
		++index;
	}
	while (index < a->len)
	{
		if (a->table[index] > tmp_len)
			++count_top;
		++index;
	}
	return (return_check(a, count_top, count_bottom));
}
