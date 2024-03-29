/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:05:39 by gulee             #+#    #+#             */
/*   Updated: 2022/01/14 00:42:46 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	index;

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free (s1);
	return (ptr);
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
