/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_all_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:03:29 by gulee             #+#    #+#             */
/*   Updated: 2022/08/04 21:53:55 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_free(void *ptr1, void *ptr2)
{
	if (ptr1)
	{
		free(ptr1);
		ptr1 = NULL;
	}
	if (ptr2)
	{
		free(ptr2);
		ptr2 = NULL;
	}
}
