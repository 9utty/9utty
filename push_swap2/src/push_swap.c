/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:36:34 by gulee             #+#    #+#             */
/*   Updated: 2022/07/27 18:23:35 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b)
{
	if (a->len <= 5)
		small_sorting(a, b);
	else
		push_sort(a, b);
}

static void	struct_init(t_stack *a, t_stack *b)
{
	a->len = 0;
	a->size = 1;
	a->table = malloc(sizeof(int));
	if (!a->table)
		push_swap_error(NULL);
	b->len = 0;
	b->size = 0;
	b->table = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2 || argv_empty(argv) == FALSE_E)
		push_swap_error(NULL);
	struct_init(&stack_a, &stack_b);
	arg_validation(argc, argv, &stack_a);
	is_same_number(&stack_a);
	if (is_sorted(&stack_a))
	{
		free(stack_a.table);
		exit(0);
	}
	make_index(&stack_a);
	set_stack_b(&stack_b, &stack_a, stack_a.len);
	push_swap(&stack_a, &stack_b);
	free(stack_a.table);
	free(stack_b.table);
	return (0);
}
