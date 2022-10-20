/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:10:57 by gulee             #+#    #+#             */
/*   Updated: 2021/12/01 12:16:12 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	size;
	size_t	index;

	size = ft_strlen(str);
	if (c == 0)
		return ((char *)&str[size]);
	index = 0;
	while (index < size)
	{
		if (str[size - index - 1] == (char)c)
			return ((char *)&str[size - index - 1]);
		index++;
	}
	return (NULL);
}
