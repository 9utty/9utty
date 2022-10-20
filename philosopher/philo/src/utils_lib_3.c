/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:33:53 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 11:02:09 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_isdigit(char num)
{
	if (num >= '0' && num <= '9')
		return (TRUE_E);
	return (FALSE_E);
}

char	*ft_strdup(char *str)
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

int	error_print(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}
