/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:49:07 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/30 09:28:08 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	storage(int *item)
{
	static int	times;
	static int	coordinates_copy;

	if (item == NULL)
		times = 0;
	else
	{
		if (times == 0)
		{
			coordinates_copy = *item;
			times++;
		}
		else
			*item = coordinates_copy;
	}
}
