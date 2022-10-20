/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:43:20 by gulee             #+#    #+#             */
/*   Updated: 2021/11/30 16:41:59 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen(src);
	if (destsize > 0)
	{
		while ((src[index]) && (index < (destsize - 1)))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (len);
}
