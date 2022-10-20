/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:38:12 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 02:48:26 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
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
	while (index++ < size)
		dest[index] = str[index];
	dest[index] = '\0';
	free (dest);
	return (dest);
}

int	ft_strcmp(char *src, char *str)
{
	int	index;
	int	tmp_index;
	int	size;

	index = 0;
	tmp_index = 0;
	size = ft_strlen(str);
	while (index < size && str[index] != '\n')
	{
		if (src[index] == str[index])
			++tmp_index;
		++index;
	}
	if (tmp_index == size)
		return (TRUE_E);
	else
		return (FALSE_E);
}
