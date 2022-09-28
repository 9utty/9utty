/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:48:17 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 08:16:15 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] && s2[index])
	{
		if (s1[index] == s2[index])
			index++;
		else
			break ;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
