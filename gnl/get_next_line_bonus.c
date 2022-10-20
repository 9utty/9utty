/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:58:17 by gulee             #+#    #+#             */
/*   Updated: 2022/01/14 17:43:06 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_get_check(const char *str)
{
	if (!str)
		return (FALSE);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

static char	*ft_get_rework(char *str)
{
	size_t	count;
	char	*temp;

	count = 0;
	temp = str;
	if (!*str)
		return (NULL);
	while (*temp != '\0' && *temp != '\n')
	{
		count++;
		temp++;
	}
	return (ft_substr(str, 0, count + 1));
}

static char	*ft_get_rest(char *str)
{
	size_t	count;
	size_t	len;
	char	*buff;
	char	*temp;

	count = 0;
	len = ft_strlen(str);
	temp = str;
	if (!str)
		return (NULL);
	while (*temp)
	{
		if (*temp == '\n')
		{
			buff = ft_substr(str, count + 1, len - count + 1);
			free(str);
			return (buff);
		}
		temp++;
		count++;
	}
	free(str);
	return (NULL);
}

static char	*ft_get_read(char *str, int fd)
{
	char	*buff;
	ssize_t	read_size;

	buff = NULL;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_size = 1;
	while (ft_get_check(str) == FALSE && read_size != 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free (buff);
			buff = NULL;
			return (NULL);
		}
		buff[read_size] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	buff = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*temp[C_OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	temp[fd] = ft_get_read(temp[fd], fd);
	if (!temp[fd])
		return (NULL);
	buff = ft_get_rework(temp[fd]);
	temp[fd] = ft_get_rest(temp[fd]);
	return (buff);
}
