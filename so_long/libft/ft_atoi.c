/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:01:57 by gulee             #+#    #+#             */
/*   Updated: 2021/12/07 11:45:48 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	index;
	size_t	result;
	int		negative;

	index = 0;
	result = 0;
	negative = 1;
	while (str[index] != '\0' && (ft_isspace(str[index])))
		index++;
	if (str[index] != '\0' && (str[index] == '-' || str[index] == '+'))
	{
		if (str[index] == '-')
			negative = -1;
		index++;
	}
	while (str[index] != '\0' && ft_isdigit(str[index]))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	if (result >= 9223372036854775808UL && negative == -1)
		return (0);
	else if (result >= 9223372036854775807 && negative == 1)
		return (-1);
	return ((int)(result * negative));
}
