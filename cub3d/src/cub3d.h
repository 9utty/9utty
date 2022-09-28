/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:51:42 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 10:05:57 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define EQUAL 0
# define FLOOR "F"
# define CEILLING "C"
# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

typedef enum e_bool
{
	FALSE_E,
	TRUE_E
}	t_bool;

typedef enum e_key
{
	RIGHT_D_E = 2,
	LEFT_A_E = 0,
	DOWN_S_E = 1,
	UP_W_E = 13,
	RIGHT_E = 124,
	LEFT_E = 123
	ESC_E = 53,
	WIN_CLOSE = 17
}	t_key;

typedef struct s_image
{
	void	*img_pointer;
	int		width;
	int		height;
	char	*filename;
}			t_image;

typedef struct s_map
{
	t_image	no;
	t_image	so;
	t_image	we;
	t_image	ea;
	ssize_t	f_color;
	ssize_t	c_color;
	char	**data;
	int		height;
	int		max_wid;
}			t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	speed;
}			t_player;

typedef struct s_table
{
	void		*mlx;
	void		*win;
	void		*main_img;
	t_map		map;
	t_player	player;
	t_image		minimap;
	int			mouse_x;
}				t_table;

/* ================================================================
							utils
================================================================= */
void	*ft_memset(void *ptr, int value, size_t num);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(const char *str, char c);
char	*get_next_line(int fd);
void	err_put(void);

/* get_next_line */
char	*get_next_line(int fd);
size_t	ft_gnl_strlen(char *str);
char	*ft_gnl_substr(char *s, size_t start, size_t len);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(char *str);

/* ================================================================
							init
================================================================= */
void	init_cub3d(t_table *table);

/* ================================================================
							parser
================================================================= */
void	parser(t_table *table);

/* utils */
int		line_count(char *filename);

/* validation */
t_bool	file_expention(char *to, char *find);
void	valid_cub_value(char **cub);

#endif
