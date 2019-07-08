/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:37:28 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 08:58:11 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		mem_for_piece(t_form *piece, t_compens *offsets)
{
	int		i;
	int		height;
	int		width;

	i = 0;
	height = piece->height - offsets->second - offsets->fourth + 1;
	width = piece->width - offsets->first - offsets->third + 1;
	piece->shape = (int**)malloc(sizeof(int*) * height);
	while (i < height - 1)
		piece->shape[i++] = (int*)malloc(sizeof(int) * width);
	piece->shape[i] = NULL;
	piece->h = height - 1;
	piece->w = width - 1;
}

static void	transfer_array(int *dst, int *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
}

static int	all_coord(t_form *piece, t_form *board, int *coordinates)
{
	t_count a;

	a.i = coordinates[0];
	a.j = coordinates[1];
	a.i_cr = a.i + piece->h;
	a.j_cr = a.j + piece->w;
	a.sum = 0;
	while (a.i < a.i_cr)
	{
		while (a.j < a.j_cr)
			a.sum += board->c_form[a.i][a.j++];
		a.j = coordinates[1];
		a.i++;
	}
	return (a.sum);
}

void		help_coord(t_count *a, t_form *piece, t_form *brd)
{
	a->smallest_sum = all_coord(piece, brd, a->coordinates_copy);
	transfer_array(a->winning_coordinates, a->coordinates_copy);
}

void		coordinates(t_form *piece, t_compens *o, t_form *brd, t_player *p)
{
	t_count a;

	a.coordinates[0] = 0;
	a.coordinates[1] = 0;
	a.winning_coordinates[0] = -100;
	a.winning_coordinates[1] = -100;
	a.smallest_sum = 999999999;
	while (a.coordinates[0] < brd->height - piece->h + 1)
	{
		while (a.coordinates[1] < brd->width - piece->w + 1)
		{
			transfer_array(a.coordinates_copy, a.coordinates);
			if (piece_found(piece, brd, a.coordinates, p)
			&& coincidance(piece, brd, a.coordinates, p)
			&& all_coord(piece, brd, a.coordinates_copy) < a.smallest_sum)
				help_coord(&a, piece, brd);
			transfer_array(a.coordinates, a.coordinates_copy);
			a.coordinates[1]++;
		}
		a.coordinates[1] = 0;
		a.coordinates[0]++;
	}
	print_c(a.winning_coordinates, &o);
}
