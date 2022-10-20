/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:21:32 by gulee             #+#    #+#             */
/*   Updated: 2022/07/27 20:01:21 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_order_num	return_num(char **ptr, int order_num)
{
	t_order_num	tmp;
	int			index;

	index = 0;
	tmp = (t_order_num)order_num;
	while (index < 11)
	{
		free(ptr[index]);
		++index;
	}
	return (tmp);
}

static t_order_num	check_order(char *str, t_stack *a, t_stack	*b)
{
	char	*flag;
	char	**ptr;
	int		index;

	index = 0;
	flag = "sa sb ss pa pb ra rb rr rra rrb rrr";
	ptr = ft_split(flag, ' ');
	while (index < 11)
	{
		if (ft_strcmp(ptr[index], str) == TRUE_E)
			return (return_num(ptr, index));
		++index;
	}
	index = 0;
	while (index < 11)
	{
		free(ptr[index]);
		ptr[index] = NULL;
		++index;
	}
	free(b->table);
	free(a->table);
	push_swap_error(NULL);
	return (0);
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

static int	result_check(t_stack *a, t_stack *b)
{
	if ((is_sorted(a) == TRUE_E) && (is_empty(b) == FALSE_E))
	{
		free(a->table);
		free(b->table);
		a->table = NULL;
		b->table = NULL;
		write(1, "OK\n", 3);
		return (0);
	}
	else
	{
		free(a->table);
		free(b->table);
		a->table = NULL;
		b->table = NULL;
		write(1, "KO\n", 3);
		return (0);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*buff;

	buff = NULL;
	struct_init(&stack_a, &stack_b);
	arg_validation(argc, argv, &stack_a);
	is_same_number(&stack_a);
	make_index(&stack_a);
	set_stack_b(&stack_b, &stack_a, stack_a.len);
	buff = read_order(0);
	while (buff != NULL)
	{
		if (read_order_check(buff) == FALSE_E)
		{
			free(stack_a.table);
			push_swap_error(&stack_b);
		}
		order_sort(&stack_a, &stack_b, check_order(buff, &stack_a, &stack_b));
		free(buff);
		buff = read_order(0);
	}
	free(buff);
	return (result_check(&stack_a, &stack_b));
}
