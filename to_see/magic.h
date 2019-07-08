/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 08:42:21 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 09:04:50 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAGIC_H
# define MAGIC_H

# include <ncurses.h>
# include "../includes/filler.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct	s_square
{
	int			x;
	int			y;
	char		**arr;
}				t_square;

int				print_result(WINDOW **result, char **game_arr);
void			print_game(char **game_arr, t_square *show_map);

#endif
