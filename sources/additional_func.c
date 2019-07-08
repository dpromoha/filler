/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:36:29 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 08:47:41 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		what_is_piece(t_form *piece, t_compens *offsets)
{
	t_count a;
	int		m;
	int		n;

	mem_for_piece(piece, offsets);
	a.i = offsets->second;
	a.j = offsets->first;
	m = 0;
	n = 0;
	while (a.i < piece->height - offsets->fourth)
	{
		while (a.j < piece->width - offsets->third)
			piece->shape[m][n++] = piece->form[a.i][a.j++];
		piece->shape[m][n] = '\0';
		a.j = offsets->first;
		a.i++;
		m++;
		n = 0;
	}
}

void			help_filler(t_form **piece, t_compens **offsets, char **line)
{
	(*piece) = create_piece(*line);
	(*offsets) = atack(*piece);
	what_is_piece((*piece), (*offsets));
}

void			print_c(int *winning_coordinates, t_compens **o)
{
	if (winning_coordinates[0] != -100)
	{
		ft_printf("%d %d\n", winning_coordinates[0] - (*o)->second,
			winning_coordinates[1] - (*o)->first);
	}
	else
		ft_printf("0 0\n");
}

static void		mem_map(char **line, t_form **map)
{
	(*map) = (t_form*)malloc(sizeof(t_form));
	(*map)->height = h(*line);
	(*map)->width = w(*line);
	(*map)->c_form = (int**)malloc(sizeof(int*) * (*map)->height + 1);
	(*map)->form = (int**)malloc(sizeof(int*) * (*map)->height + 1);
}

t_form			*more_mem_map(char *line)
{
	int		i;
	t_form	*map;

	mem_map(&line, &map);
	i = 0;
	while (i < map->height)
	{
		map->form[i] = (int *)malloc(sizeof(int) * map->width + 1);
		map->c_form[i] = (int *)malloc(sizeof(int) * map->width + 1);
		i++;
	}
	map->form[i] = NULL;
	map->c_form[i] = NULL;
	return (map);
}
