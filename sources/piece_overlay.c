/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_overlay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:37:40 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/27 14:37:41 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	initial(int *i, int *j, int *coordinates)
{
	(*i)++;
	*j = 0;
	coordinates[0]++;
	storage(&coordinates[1]);
}

static void	help_to_coi(t_count *a, int *c, t_form *piece, int *above)
{
	a->i_cr = c[0] + piece->h;
	a->j_cr = c[1] + piece->w;
	a->i = 0;
	a->j = 0;
	*above = 0;
	storage(&c[1]);
}

int			coincidance(t_form *piece, t_form *board, int *c, t_player *p)
{
	t_count a;
	int		above;

	storage(NULL);
	help_to_coi(&a, c, piece, &above);
	while (c[0] < a.i_cr)
	{
		while (c[1] < a.j_cr)
		{
			if (board->form[c[0]][c[1]] == p->for_hero
			&& piece->shape[a.i][a.j] == '*')
				above++;
			else if (board->form[c[0]][c[1]] == p->for_enemy
			&& piece->shape[a.i][a.j] == '*')
				return (0);
			a.j++;
			c[1]++;
		}
		initial(&a.i, &a.j, c);
	}
	if (above == 1)
		return (1);
	return (0);
}
