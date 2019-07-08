/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   around.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:36:37 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 08:48:39 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	one_side(int **tab, int *coordinates, int height, int width)
{
	t_count a;

	a.i = coordinates[0];
	a.j = coordinates[1];
	if (a.i < (height - 1) && tab[a.i + 1][a.j] == '.')
		tab[a.i + 1][a.j] = 100;
	if (a.i > 0 && tab[a.i - 1][a.j] == '.')
		tab[a.i - 1][a.j] = 100;
	if (a.j < (width - 1) && tab[a.i][a.j + 1] == '.')
		tab[a.i][a.j + 1] = 100;
	if (a.j > 0 && tab[a.i][a.j - 1] == '.')
		tab[a.i][a.j - 1] = 100;
}

static void	around(int height, int width, int *coordinates, int ***tab)
{
	t_count a;

	one_side((*tab), coordinates, height, width);
	a.i = coordinates[0];
	a.j = coordinates[1];
	if (a.i < (height - 1) && a.j < (width - 1) &&
		(*tab)[a.i + 1][a.j + 1] == '.')
		(*tab)[a.i + 1][a.j + 1] = 100;
	if (a.i < (height - 1) && a.j > 0 && (*tab)[a.i + 1][a.j - 1] == '.')
		(*tab)[a.i + 1][a.j - 1] = 100;
	if (a.i > 0 && a.j < (width - 1) && (*tab)[a.i - 1][a.j + 1] == '.')
		(*tab)[a.i - 1][a.j + 1] = 100;
	if (a.i > 0 && a.j > 0 && (*tab)[a.i - 1][a.j - 1] == '.')
		(*tab)[a.i - 1][a.j - 1] = 100;
}

void		check_around(int **tab, int height, int width, int for_enemy)
{
	t_count a;
	int		coordinates[2];

	a.i = 0;
	while (a.i < height)
	{
		a.j = 0;
		while (a.j < width)
		{
			if (tab[a.i][a.j] == for_enemy)
			{
				coordinates[0] = a.i;
				coordinates[1] = a.j;
				around(height, width, coordinates, &tab);
			}
			a.j++;
		}
		a.i++;
	}
}

void		check_read(char **line, t_form **brd, t_player **p)
{
	if (ft_strncmp((*line), "Plateau", 7) == 0)
	{
		(*brd) = mem_for_new(*line);
		find_space((*brd)->c_form, (*brd)->height, (*brd)->width,
			(*p)->for_hero);
		create_map((*brd), (*p)->for_enemy);
	}
}

void		hero(t_player **players)
{
	(*players)->what_is_player = 2;
	(*players)->for_hero = 'X';
	(*players)->enemy = 1;
	(*players)->for_enemy = 'O';
}
