/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:41:31 by gulee             #+#    #+#             */
/*   Updated: 2022/07/01 01:00:00 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>

typedef enum e_enum{
	FALSE_E = 0,
	TRUE_E
}	t_enum;

typedef struct s_data {
	char	**map;
	void	*mlx;
	void	*window;
	void	*img_ground;
	void	*img_wall;
	void	*img_player;
	void	*img_collec;
	void	*img_exit;
	int		player_x;
	int		player_y;
	int		img_hgt;
	int		img_wid;
	int		exit_count;
	int		exit_x;
	int		exit_y;
	int		item_count;
	int		player_count;
	int		hgt;
	int		wid;
	int		move_count;
}			t_data;

void	error_all(t_data *data);
void	error_game(t_data *data);
void	free_map(char **map);
int		so_long_exit(t_data *data);

void	map_read(t_data *data, char *file_name);
int		check_map(t_data *data);

int		parsing_map_value(t_data *data);
int		parsing_map_value_validi(t_data *data);
int		parsing_map_square(t_data *data);
int		parsing_map_wall(t_data *data);

void	window_map(t_data *data);
void	put_img(t_data *data, void *img_value, int x, int y);
void	put_player_img(t_data *data, int x, int y);
void	put_exit_img(t_data *data);

int		move_key(int key_num, t_data *data);

char	*get_next_line(int fd);
char	*ft_gnl_substr(char *s, size_t start, size_t len);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(char *str);
size_t	ft_gnl_strlen(char *str);

#endif
