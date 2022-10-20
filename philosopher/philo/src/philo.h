/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:43:22 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 17:31:11 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_bool
{
	FALSE_E = 0,
	TRUE_E = 1
}	t_bool;

typedef enum e_state
{
	NO_E = 0,
	YES_E = 1,
	FINISH_E = 2
}	t_state;

typedef enum e_action
{
	FORK_E = 0,
	EATING_E = 1,
	SLEEPING_E = 2,
	THINKING_E = 3,
	DIED_E = 4
}	t_action;

typedef struct s_arg
{
	int						philo_max;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						must_eat_count;
	ssize_t					start_time;
	pthread_mutex_t			print_mutex;
	pthread_mutex_t			die_mutex;
	pthread_mutex_t			eat_time_mutex;
	pthread_mutex_t			finish_mutex;
	int						finish_count;
	int						stop;
}							t_table;

typedef struct s_philo
{
	int						philo_id;
	pthread_t				thread_id;
	pthread_t				thread_die;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	t_table					*table;
	ssize_t					last_eat_time;
	unsigned int			eat_count;
	int						finish;
}							t_philo;

typedef struct s_ptr
{
	t_philo					*philo;
	t_table					table;
}							t_ptr;

/* ================================================
					utils
================================================ */
ssize_t			ft_atoi(const char *str);
t_bool			ft_isdigit(char num);
char			*ft_strdup(char *str);
ssize_t			time_to_time(void);
void			ft_putstr_fd(char *s, int fd);
void			philo_pause(ssize_t time_in_ms);
int				ft_strlen(char *str);

/* ================================================
					parser
================================================ */
int				parser(int argc, char **argv, t_ptr *ptr);
t_bool			check_arg(int argc, char **argv);

/* ================================================
					init
================================================ */
int				init(t_ptr *ptr);
int				error_print(char *str);

/* ================================================
					print
================================================ */
void			state_print(t_philo *philo, t_action action, char **str);
char			**get_str(void);

/* ================================================
					philo
================================================ */
int				start(t_ptr *ptr);
int				die_check(t_philo *philo, int i);

/* ================================================
					action
================================================ */
void			action(t_philo *philo);

#endif
