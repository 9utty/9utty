/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 03:34:14 by gulee             #+#    #+#             */
/*   Updated: 2021/11/30 22:51:10 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned int	index;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		while (num > 0)
		{
			num--;
			*(char *)(dest + num) = *(const char *)(src + num);
		}
	}
	else
	{
		index = 0;
		while (index < num)
		{
			*(char *)(dest + index) = *(const char *)(src + index);
			index++;
		}
	}
	return (dest);
}
