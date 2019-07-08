/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:35:30 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/27 14:35:32 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "filler.h"

typedef	struct			s_compens
{
	int					first;
	int					second;
	int					third;
	int					fourth;
}						t_compens;

typedef	struct			s_form
{
	int					**form;
	int					**c_form;
	int					**shape;
	int					height;
	int					width;
	int					h;
	int					w;
}						t_form;

typedef	struct			s_player
{
	int					what_is_player;
	int					for_hero;
	int					enemy;
	int					for_enemy;
}						t_player;

typedef	struct			s_count
{
	int					i;
	int					j;
	int					coordinates[2];
	int					coordinates_copy[2];
	int					winning_coordinates[2];
	int					smallest_sum;
	int					dimensions[2];
	int					sum;
	int					i_cr;
	int					j_cr;
}						t_count;

#endif
