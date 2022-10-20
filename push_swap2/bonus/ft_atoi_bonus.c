/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:32:02 by gulee             #+#    #+#             */
/*   Updated: 2022/07/27 18:10:57 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	result;
	int		negative;

	result = 0;
	negative = 1;
	while (*str != '\0' && (ft_isspace(*str)))
		str++;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
		if ((negative == -1 && result > 2147483648) || \
			(negative == 1 && result >= 2147483648))
			push_swap_error(NULL);
	}
	return ((int)(result * negative));
}
