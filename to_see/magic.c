/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:39:27 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 09:03:24 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magic.h"

static void		who_it_is(WINDOW *map_w, int i, int j, char c)
{
	short color_pair;

	color_pair = 0;
	init_pair(1, COLOR_BLACK, COLOR_CYAN);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	if (c == 'O' || c == 'o')
		color_pair = 2;
	else if (c == 'X' || c == 'x')
		color_pair = 1;
	else if (c == '.')
		color_pair = 3;
	wattron(map_w, COLOR_PAIR(color_pair));
	mvwprintw(map_w, i, j * 2 - 3, "   ", c);
	wattroff(map_w, COLOR_PAIR(color_pair));
}

static void		frame(t_square *show_map, WINDOW **map_w, WINDOW **result)
{
	t_square a;

	a.y = 0;
	a.x = 0;
	a.y = show_map->y;
	a.x = show_map->x;
	*map_w = newwin(a.y + (2 * 2), a.x * 2 + 3 +
		(4 * 2), 5, 0);
	*result = newwin(10, 18, 10, a.x * 3 + 3 +
		(4 * 3));
	box(*result, 0, 0);
	wrefresh(*map_w);
	box(*map_w, 0, 0);
}

static void		draw(WINDOW *map_w, char **game_arr, t_square *show_map)
{
	t_count a;

	a.i = 2;
	while (a.i < show_map->y + 2)
	{
		a.j = 4;
		while (a.j < show_map->x + 4)
		{
			who_it_is(map_w, a.i, a.j, game_arr[a.i][a.j]);
			a.j++;
		}
		a.i++;
	}
}

void			print_game(char **game_arr, t_square *show_map)
{
	int		i;
	WINDOW	*map_w;
	WINDOW	*result;

	i = 0;
	initscr();
	curs_set(0);
	start_color();
	frame(show_map, &map_w, &result);
	while (game_arr[i])
	{
		while (game_arr[i] != NULL && !ft_strstr(game_arr[i], "Plateau")
				&& !ft_strstr(game_arr[i], "== O fin"))
			i++;
		if (print_result(&result, game_arr + i) == 1)
			break ;
		draw(map_w, game_arr + i, show_map);
		usleep(10000);
		wrefresh(map_w);
		i++;
	}
	getch();
	endwin();
}
