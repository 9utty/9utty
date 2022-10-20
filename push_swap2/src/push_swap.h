/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:34:21 by gulee             #+#    #+#             */
/*   Updated: 2022/07/27 18:23:23 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef enum e_enum
{
	FALSE_E = 0,
	TRUE_E = 1
}	t_enum;

typedef enum e_order_num
{
	SA_E,
	SB_E,
	SS_E,
	PA_E,
	PB_E,
	RA_E,
	RB_E,
	RR_E,
	RRA_E,
	RRB_E,
	RRR_E
}	t_order_num;

typedef struct s_stack
{
	int	*table;
	int	len;
	int	size;
}		t_stack;

/* validation check */
void	arg_validation(int argc, char **argv, t_stack *a);
void	is_same_number(t_stack *stack);
int		is_empty(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_isnum(char *num);
int		ft_isdigit(char c);
int		argv_empty(char **argv);

/* stack init */
void	init_stack(t_stack *stack);
void	set_stack_a(t_stack *a, int num);
void	set_stack_b(t_stack *b, t_stack *a, int size);

/* libft utils */
char	**ft_split(const char *str, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *str);
void	array_free(char **str);
void	*ft_memcpy(void *dest, const void *src, size_t num);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

/* error */
void	push_swap_error(t_stack *stack);

/* stack utils */
int		stack_top(t_stack *stack);
int		stack_bottom(t_stack *stack);

/* indexing utils */
void	make_index(t_stack *a);

/* sort utils */
int		swap(t_stack *stack);
int		push(t_stack *to, t_stack *from);
int		rotation(t_stack *stack);
int		revers_rotation(t_stack *stack);
int		sort_check(t_stack *a);

/* sa sb ss */
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);

/* pa pb */
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_b, t_stack *stack_a);

/* ra rb rr */
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);

/* rra rrb rrr */
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrr(t_stack *a, t_stack *b);

/* push_swap */
void	order_sort(t_stack *a, t_stack *b, t_order_num key);
void	push_sort(t_stack *a, t_stack *b);
void	small_sorting(t_stack *a, t_stack *b);

#endif
