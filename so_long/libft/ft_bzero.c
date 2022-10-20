/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:19:51 by gulee             #+#    #+#             */
/*   Updated: 2021/11/21 16:53:18 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t			index;
	unsigned char	*sptr;

	index = 0;
	sptr = (unsigned char *)ptr;
	while (index < size)
	{
		sptr[index] = 0;
		index++;
	}
	ptr = sptr;
}
