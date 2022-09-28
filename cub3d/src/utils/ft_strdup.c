/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:27:51 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 07:21:21 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	size;
	size_t	index;

	index = 0;
	size = ft_strlen(str);
	dest = NULL;
	dest = malloc((sizeof(char) * size) + 1);
	if (!dest)
		return (NULL);
	while (index < size)
	{
		dest[index] = str[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
