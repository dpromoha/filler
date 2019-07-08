/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:54:24 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/29 12:54:25 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		double_free(char **two_d)
{
	int		i;

	i = 0;
	while (two_d[i] != NULL)
		free(two_d[i++]);
	if (two_d != NULL)
		free(two_d);
}

static void	double_free_int(int **two_d)
{
	int		i;

	i = 0;
	while (two_d[i] != NULL)
		free(two_d[i++]);
	if (two_d != NULL)
		free(two_d);
}

static void	map_free(t_form *board)
{
	double_free_int(board->form);
	double_free_int(board->c_form);
	free(board);
}

static void	random_free(t_form *piece)
{
	double_free_int(piece->form);
	double_free_int(piece->c_form);
	double_free_int(piece->shape);
	free(piece);
}

void		free_launcher(t_form *board, t_form *piece, t_compens *offsets)
{
	map_free(board);
	random_free(piece);
	free(offsets);
}
