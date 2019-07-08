/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:45:34 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/29 12:45:35 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	one_side(int **tab, int *coords, int *dimensions, int current)
{
	t_count a;
	int		height;
	int		width;

	a.i = coords[0];
	a.j = coords[1];
	height = dimensions[0];
	width = dimensions[1];
	if (a.i < (height - 1) && tab[a.i + 1][a.j] == '.' &&
		tab[a.i][a.j] != current)
		tab[a.i + 1][a.j] = current;
	if (a.i > 0 && tab[a.i - 1][a.j] == '.' && tab[a.i][a.j] != current)
		tab[a.i - 1][a.j] = current;
	if (a.j < (width - 1) && tab[a.i][a.j + 1] == '.' &&
		tab[a.i][a.j] != current)
		tab[a.i][a.j + 1] = current;
	if (a.j > 0 && tab[a.i][a.j - 1] == '.' && tab[a.i][a.j] != current)
		tab[a.i][a.j - 1] = current;
	if ((a.i < (height - 1) && tab[a.i + 1][a.j] == current) ||
	(a.i > 0 && tab[a.i - 1][a.j] == current)
	|| (a.j < (width - 1) && tab[a.i][a.j + 1] == current) ||
	(a.j > 0 && tab[a.i][a.j - 1] == current))
		return (1);
	else
		return (0);
}

static int	helpful(int ***tab, t_count a, int height, int c)
{
	if ((a.i < (height - 1) && (*tab)[a.i + 1][a.j + 1] == c) ||
	(a.i < (height - 1) && (*tab)[a.i + 1][a.j - 1] == c)
	|| (a.i > 0 && (*tab)[a.i - 1][a.j + 1] == c) ||
	(a.i > 0 && (*tab)[a.i - 1][a.j - 1] == c))
		return (1);
	else
		return (1);
}

static int	another_side(int **tab, int *coordinates, int *dimensions, int c)
{
	t_count a;
	int		height;
	int		width;

	a.i = coordinates[0];
	a.j = coordinates[1];
	height = dimensions[0];
	width = dimensions[1];
	if (a.i < (height - 1) && a.j < (width - 1) && tab[a.i + 1][a.j + 1] == '.'
	&& tab[a.i][a.j] != c)
		tab[a.i + 1][a.j + 1] = c;
	if (a.i < (height - 1) && a.j > 0 && tab[a.i + 1][a.j - 1] == '.'
	&& tab[a.i][a.j] != c)
		tab[a.i + 1][a.j - 1] = c;
	if (a.i > 0 && a.j < (width - 1) && tab[a.i - 1][a.j + 1] == '.'
		&& tab[a.i][a.j] != c)
		tab[a.i - 1][a.j + 1] = c;
	if (a.i > 0 && a.j > 0 && tab[a.i - 1][a.j - 1] == '.' &&
		tab[a.i][a.j] != c)
		tab[a.i - 1][a.j - 1] = c;
	if (helpful(&tab, a, height, c) == 1)
		return (1);
	return (0);
}

static void	in(t_count *a)
{
	a->i = 0;
	a->j = 0;
	a->sum = 0;
}

int			algorithm(int **tab, int height, int width, int current)
{
	t_count a;

	in(&a);
	while (a.i < height)
	{
		a.j = 0;
		while (a.j++ < width)
		{
			if (tab[a.i][a.j] >= 100)
			{
				a.coordinates[0] = a.i;
				a.coordinates[1] = a.j;
				a.dimensions[0] = height;
				a.dimensions[1] = width;
				if (one_side(tab, a.coordinates, a.dimensions, current) != 0
				&& another_side(tab, a.coordinates, a.dimensions, current) != 0)
					a.sum = 1;
			}
		}
		a.i++;
	}
	if (a.sum == 1)
		return (1);
	return (0);
}
