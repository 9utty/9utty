/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:27:51 by gulee             #+#    #+#             */
/*   Updated: 2022/07/12 18:34:13 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


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
