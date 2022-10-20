/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:17:18 by gulee             #+#    #+#             */
/*   Updated: 2021/11/13 03:20:43 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t size)
{
	const char	*sptr;
	size_t		count;

	count = 0;
	sptr = (const char *)ptr;
	while (count < size)
	{
		if (sptr[count] == (const char)c)
			return ((void *)&sptr[count]);
		count++;
	}
	return (NULL);
}
