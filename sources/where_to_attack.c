/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_to_attack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:38:09 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/27 14:38:10 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	first_side(t_form *map_form)
{
	t_count a;

	a.i = 0;
	a.j = 0;
	while (a.j < map_form->width)
	{
		while (a.i < map_form->height &&
			map_form->form[a.i][a.j] == '.')
			a.i++;
		if (map_form->form[a.i] == '\0')
		{
			a.j++;
			a.i = 0;
		}
		else
			break ;
	}
	return (a.j);
}

static int	second_side(t_form *map_form)
{
	t_count a;

	a.i = 0;
	a.j = 0;
	while (map_form->form[a.i] != '\0')
	{
		while (a.j < map_form->width &&
			map_form->form[a.i][a.j] == '.')
			a.j++;
		if (map_form->form[a.i][a.j] == '\0')
		{
			a.i++;
			a.j = 0;
		}
		else
			break ;
	}
	return (a.i);
}

static int	third_side(t_form *map_form)
{
	t_count a;
	int		result;

	a.i = 0;
	a.j = map_form->width - 1;
	while (a.j >= 0)
	{
		while (a.i < map_form->height &&
			map_form->form[a.i][a.j] == '.')
			a.i++;
		if (map_form->form[a.i] == '\0')
		{
			a.j--;
			a.i = 0;
		}
		else
			break ;
	}
	result = map_form->width - a.j - 1;
	return (result);
}

static int	fourth_side(t_form *map_form)
{
	t_count a;

	a.i = map_form->height - 1;
	a.j = 0;
	while (a.i >= 0)
	{
		while (map_form->form[a.i][a.j] == '.')
			a.j++;
		if (map_form->form[a.i][a.j] == '\0')
		{
			a.i--;
			a.j = 0;
		}
		else
			break ;
	}
	return (map_form->height - a.i - 1);
}

t_compens	*atack(t_form *map_form)
{
	t_compens	*offsets;

	offsets = (t_compens*)malloc(sizeof(t_compens));
	offsets->first = first_side(map_form);
	offsets->second = second_side(map_form);
	offsets->third = third_side(map_form);
	offsets->fourth = fourth_side(map_form);
	return (offsets);
}
