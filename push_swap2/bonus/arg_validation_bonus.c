/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:25:39 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 14:09:41 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	num_validi(int num, char **argv, int index_num)
{
	int	index;

	index = index_num + 1;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) == num)
			return (FALSE_E);
		++index;
	}
	return (TRUE_E);
}

static void	push_num(char **tmp_argv, int tmp_num, int index, t_stack *a)
{
	if (!ft_isnum(tmp_argv[index]))
		push_swap_error(a);
	tmp_num = ft_atoi(tmp_argv[index]);
	if (!num_validi(tmp_num, tmp_argv, index))
		push_swap_error(a);
	if (tmp_num < -2147483648 || tmp_num > 2147483647)
		push_swap_error(a);
	set_stack_a(a, tmp_num);
}

void	arg_validation(int argc, char **argv, t_stack *a)
{
	int		index;
	int		tmp_num;
	char	**tmp_argv;

	tmp_num = 0;
	index = 0;
	if (argc == 2)
		tmp_argv = ft_split(argv[1], ' ');
	else
	{
		index = 1;
		tmp_argv = argv;
	}
	while (tmp_argv[index])
	{
		push_num(tmp_argv, tmp_num, index, a);
		++index;
	}
	if (argc == 2)
		array_free(tmp_argv);
}

int	read_order_check(char *str)
{
	char	*flag;
	char	**ptr;
	int		index;
	int		tmp_index;

	tmp_index = 0;
	index = 0;
	flag = "sa sb ss pa pb ra rb rr rra rrb rrr";
	ptr = ft_split(flag, ' ');
	while (index < 11)
	{
		if (ft_strcmp(ptr[index], str) == TRUE_E)
			++tmp_index;
		++index;
	}
	if (tmp_index != 1)
	{
		array_free(ptr);
		return (FALSE_E);
	}
	array_free(ptr);
	return (TRUE_E);
}
