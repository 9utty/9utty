/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:51:42 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 05:08:30 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

typedef enum e_bool
{
	TRUE_E,
	FALSE_E
}	t_bool;

typedef enum e_dir
{
	DIR_N_E,
	DIR_E_E,
	DIR_W_E,
	DIR_S_E
}	t_dir;

#endif
