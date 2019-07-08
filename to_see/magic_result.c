/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:39:35 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 09:06:52 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magic.h"

static void	print_in_box(WINDOW ***result, int o, int x)
{
	init_pair(4, COLOR_BLACK, COLOR_RED);
	wattron(**result, COLOR_PAIR(4));
	mvwprintw(**result, 2, 14 / 2 - 2, " WINNER?");
	wattron(**result, COLOR_PAIR(2) | A_STANDOUT | A_BOLD);
	mvwprintw(**result, 4, 5, "O took %d", o);
	wattroff(**result, COLOR_PAIR(2));
	wattron(**result, COLOR_PAIR(1) | A_STANDOUT | A_BOLD);
	mvwprintw(**result, 6, 5, "X took %d", x);
	wattroff(**result, COLOR_PAIR(1));
}

int			print_result(WINDOW **result, char **game_arr)
{
	int o;
	int x;

	if (ft_strstr(game_arr[0], "== O fin") != 0)
	{
		o = ft_atoi(game_arr[0] + 10);
		x = ft_atoi(game_arr[1] + 10);
		init_pair(1, COLOR_BLACK, 6);
		init_pair(2, COLOR_BLACK, 7);
		print_in_box(&result, o, x);
		wrefresh(*result);
		usleep(3000000);
		return (1);
	}
	return (0);
}
