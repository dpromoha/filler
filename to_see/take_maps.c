/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:41:29 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 09:12:04 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magic.h"

static void	help_j_free(char **s1, char *s2)
{
	char *copy;

	if (!*s1 || !s1)
		return ;
	else
		copy = *s1;
	*s1 = ft_strjoin(*s1, s2);
	ft_strdel(&copy);
}

static char	*from_term(void)
{
	char	*input;
	char	*what_is;
	char	*after;

	what_is = NULL;
	input = NULL;
	while (gnl(0, &input) > 0)
	{
		if (what_is == NULL)
			what_is = ft_strdup(input);
		else
			help_j_free(&what_is, input);
		after = ft_strdup("\n");
		help_j_free(&what_is, after);
		ft_strdel(&after);
		if (ft_strstr(input, "== X fin:"))
			break ;
		else
			ft_strdel(&input);
	}
	ft_strdel(&input);
	return (what_is);
}

static void	size_of_game(t_square **show_map, char *size_str)
{
	int i;

	i = 0;
	if (!((*show_map) = (t_square*)malloc(sizeof(t_square))))
		return ;
	else
	{
		while (!ft_isdigit(size_str[i]))
			i++;
		(*show_map)->y = ft_atoi(size_str + i);
		while (ft_isdigit(size_str[i]))
			i++;
		(*show_map)->x = ft_atoi(size_str + i);
		(*show_map)->arr = NULL;
	}
}

static void	start(void)
{
	initscr();
	refresh();
	curs_set(0);
	printw("###### ######  ####  ##  ## ######      ###\n");
	printw("##       ##   ##     ##  ##   ##        ###\n");
	printw("####     ##   ## ### ######   ##        ###\n");
	printw("##       ##   ##  ## ##  ##   ##           \n");
	printw("##     ######  ####  ##  ##   ##        ###\n");
	getch();
	refresh();
	endwin();
}

int			main(void)
{
	char		**game_arr;
	char		*game_str;
	t_square	*show_map;
	int			i;

	i = 0;
	game_str = from_term();
	game_arr = ft_strsplit(game_str, '\n');
	ft_strdel(&game_str);
	start();
	while (game_arr[i] != NULL && !ft_strstr(game_arr[i], "Plateau")
			&& !ft_strstr(game_arr[i], "== O fin"))
		i++;
	size_of_game(&show_map, game_arr[i]);
	print_game(game_arr + i, show_map);
	free(show_map);
	twice_free(&game_arr);
	ft_printf("%s", "\xF0\x9F\x94\xA5");
	ft_printf("%s", "\xF0\x9F\x94\xA5");
	ft_printf("  GAME OVER ");
	ft_printf("%s", "\xF0\x9F\x94\xA5");
	ft_printf("%s\n", "\xF0\x9F\x94\xA5");
	return (0);
}
