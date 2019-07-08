/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:36:54 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 08:09:04 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		what_sign(t_form *rect, char cell, int i, int j)
{
	rect->form[i][j] = cell;
	rect->c_form[i][j] = cell;
	if (cell == 'x' || cell == 'o')
	{
		rect->form[i][j] = rect->form[i][j] - 32;
		rect->c_form[i][j] = rect->c_form[i][j] - 32;
	}
}

t_form			*mem_for_new(char *line_sizes)
{
	t_count a;
	int		k;
	char	*line;
	t_form	*rect_struct;

	a.i = 0;
	a.j = 0;
	k = 4;
	rect_struct = more_mem_map(line_sizes);
	gnl(0, &line);
	line != NULL ? free(line) : 0;
	while (a.i < rect_struct->height)
	{
		gnl(0, &line);
		while (a.j < rect_struct->width)
			what_sign(rect_struct, line[k++], a.i, a.j++);
		if (line)
			free(line);
		rect_struct->form[a.i][a.j] = 0;
		rect_struct->c_form[a.i][a.j] = 0;
		a.j = 0;
		k = 4;
		a.i++;
	}
	return (rect_struct);
}

void			find_space(int **c_form, int height, int width, char for_hero)
{
	t_count a;

	a.i = 0;
	a.j = 0;
	while (a.i < height)
	{
		a.j = 0;
		while (a.j < width)
		{
			if (c_form[a.i][a.j] == for_hero)
				c_form[a.i][a.j] = '.';
			a.j++;
		}
		a.i++;
	}
}

static t_player	*hero_or_not(void)
{
	char		*line;
	char		**line_items;
	t_player	*players;

	gnl(0, &line);
	if (!line[0])
		return (NULL);
	players = (t_player*)malloc(sizeof(t_player));
	line_items = ft_strsplit(line, ' ');
	if (ft_strncmp("p1", line_items[2], 2) == 0)
	{
		players->what_is_player = 1;
		players->for_hero = 'O';
		players->enemy = 2;
		players->for_enemy = 'X';
	}
	else if (ft_strncmp("p2", line_items[2], 2) == 0)
		hero(&players);
	double_free(line_items);
	free(line);
	return (players);
}

int				main(void)
{
	t_form		*brd;
	t_form		*piece;
	t_player	*p;
	t_compens	*offsets;
	char		*line;

	if (!(p = hero_or_not()))
		return (0);
	while (gnl(0, &line) > 0)
	{
		if (line != NULL)
		{
			check_read(&line, &brd, &p);
			if (ft_strncmp(line, "Piece", 5) == 0)
			{
				help_filler(&piece, &offsets, &line);
				coordinates(piece, offsets, brd, p);
				free_launcher(brd, piece, offsets);
			}
			ft_strdel(&line);
		}
	}
	return (0);
}
