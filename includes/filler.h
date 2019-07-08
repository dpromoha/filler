/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:35:22 by dpromoha          #+#    #+#             */
/*   Updated: 2019/07/03 09:13:43 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "structure.h"

t_form					*create_piece(char *line_sizes);
t_form					*more_mem_map(char *line);
void					help_filler(t_form **piece,
						t_compens **offsets, char **line);
void					find_space(int **c_form, int height, int width,
						char for_hero);
t_form					*mem_for_new(char *line_sizes);
int						h(char *line);
int						w(char *line);
void					create_map(t_form *board, char for_enemy);
t_compens				*atack(t_form *rect_struct);
void					mem_for_piece(t_form *piece, t_compens *offsets);
void					coordinates(t_form *piece, t_compens *o,
						t_form *brd, t_player *p);
void					print_c(int *winning_coordinates, t_compens **o);
int						coincidance(t_form *piece, t_form *board,
						int *c, t_player *p);
void					check_around(int **tab, int height, int width,
						int for_enemy);
int						algorithm(int **tab, int height, int width,
						int current);
int						piece_found(t_form *piece, t_form *board,
						int *coords, t_player *players);
void					free_launcher(t_form *board, t_form *piece,
						t_compens *offsets);
void					double_free(char **two_d);
void					check_read(char **line, t_form **brd, t_player **p);
void					hero(t_player **players);

#endif
