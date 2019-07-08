/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:37:17 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/27 14:37:18 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			piece_found(t_form *piece, t_form *board, int *coords, t_player *p)
{
	t_count a;

	a.i_cr = 0;
	a.j_cr = 0;
	a.i = coords[0];
	a.j = coords[1];
	a.i_cr = coords[0] + piece->h;
	a.j_cr = coords[1] + piece->w;
	while (a.i < a.i_cr)
	{
		while (a.j < a.j_cr)
		{
			if (board->form[a.i][a.j] == p->for_hero)
				return (1);
			a.j++;
		}
		a.j = coords[1];
		a.i++;
	}
	return (0);
}

static int	dot_found(int **tab, int height, int width)
{
	t_count a;

	a.i = 0;
	a.j = 0;
	while (a.i < height)
	{
		a.j = 0;
		while (a.j < width)
		{
			if (tab[a.i][a.j] == '.')
				return (1);
			a.j++;
		}
		a.i++;
	}
	return (0);
}

void		create_map(t_form *board, char for_enemy)
{
	int	current;

	current = 100;
	check_around(board->c_form, board->height, board->width,
		for_enemy);
	while (dot_found(board->c_form, board->height, board->width))
	{
		if (algorithm(board->c_form, board->height,
			board->width, current++) == 0)
			break ;
	}
}
