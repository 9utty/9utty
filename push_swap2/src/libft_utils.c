/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:52:13 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 13:51:00 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char num)
{
	if (num >= '0' && num <= '9')
		return (TRUE_E);
	return (FALSE_E);
}

int	ft_isnum(char *num)
{
	int	index;

	index = 0;
	if ((num[0] == '-' || num[0] == '+') && !ft_isdigit(num[index + 1]))
		return (FALSE_E);
	if (num[0] == '-' || num[0] == '+')
		++index;
	while (num[index])
	{
		if (!ft_isdigit(num[index]))
			return (FALSE_E);
		++index;
	}
	return (TRUE_E);
}

void	array_free(char **str)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (str[len])
		++len;
	while (index <= len)
	{
		free(str[index]);
		str[index] = NULL;
		++index;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t	index;

	index = 0;
	if ((dest == src) || num == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	while (index < num)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dest);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int		index;

	if (!s)
		return (NULL);
	if (*s == '\0' || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) <= len)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	index = 0;
	while (s[start] && index < len)
		ptr[index++] = s[start++];
	ptr[index] = '\0';
	return (ptr);
}
