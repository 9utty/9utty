/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:46:56 by gulee             #+#    #+#             */
/*   Updated: 2022/07/27 18:21:48 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <unistd.h>

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

/* error */
void	push_swap_error(t_stack *stack);

/* libft_utils */
char	**ft_split(const char *str, char c);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_atoi(const char *str);
int		ft_strcmp(char *src, char *str);
int		ft_strlen(char *str);
int		ft_isdigit(char num);
int		ft_isnum(char *num);
void	array_free(char **str);
void	*ft_memcpy(void *dest, const void *src, size_t num);

/* validation check */
void	arg_validation(int argc, char **argv, t_stack *a);
void	is_same_number(t_stack *stack);
int		read_order_check(char *str);
int		is_sorted(t_stack *stack);
int		is_empty(t_stack *stack);
int		argv_empty(char **argv);

/* make_index */
void	make_index(t_stack *a);

/* set_stack */
void	set_stack_b(t_stack *b, t_stack *a, int size);
void	set_stack_a(t_stack *a, int num);

/* order sorting */
void	order_sort(t_stack *a, t_stack *b, t_order_num key);

/* read func */
char	*read_order(int fd);

/* sort utils */
int		push(t_stack *to, t_stack *from);
int		rotation(t_stack *stack);
int		swap(t_stack *stack);
int		revers_rotation(t_stack *stack);

/* rotation */
int		ra(t_stack *stack_a);
int		rb(t_stack *stack_b);
int		rr(t_stack *stack_a, t_stack *stack_b);

/* push */
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);

/* swap */
int		sa(t_stack *stack_a);
int		sb(t_stack *stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);

/* revers rotation */
int		rra(t_stack *stack_a);
int		rrb(t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);

#endif
