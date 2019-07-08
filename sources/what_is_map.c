/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:38:01 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/27 14:38:02 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			h(char *line)
{
	int		height;
	char	**buffer;

	buffer = ft_strsplit(line, ' ');
	height = ft_atoi(buffer[1]);
	double_free(buffer);
	return (height);
}

int			w(char *line)
{
	int		width;
	char	**buffer;

	buffer = ft_strsplit(line, ' ');
	width = ft_atoi(buffer[2]);
	double_free(buffer);
	return (width);
}

t_form		*create_piece(char *line_sizes)
{
	t_count a;
	int		k;
	char	*line;
	t_form	*rect_struct;

	a.i = 0;
	a.j = 0;
	k = 0;
	rect_struct = more_mem_map(line_sizes);
	while (a.i < rect_struct->height)
	{
		if (gnl(0, &line) > 0)
		{
			while (a.j < rect_struct->width)
				rect_struct->form[a.i][a.j++] = line[k++];
			rect_struct->form[a.i][a.j] = 0;
			k = 0;
			a.j = 0;
			a.i++;
			free(line);
		}
	}
	rect_struct->shape = NULL;
	return (rect_struct);
}
