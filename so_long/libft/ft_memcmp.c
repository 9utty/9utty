/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:21:12 by gulee             #+#    #+#             */
/*   Updated: 2021/11/24 16:31:06 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			count;
	size_t			index;

	str1 = (unsigned char *)ptr1;
	str2 = (unsigned char *)ptr2;
	count = num;
	index = 0;
	while (count)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index++;
		count--;
	}
	return (0);
}
