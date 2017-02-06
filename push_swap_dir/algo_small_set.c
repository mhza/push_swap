/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:47:43 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 17:33:22 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplest_case(int is_pila, t_pset *pset)
{
	t_val	v;
	t_link	*pile;
	char	*ope;

	pile = is_pila ? pset->pila : pset->pilb;
	v.min = get_min(is_pila, pset);
	v.min2 = get_min2(is_pila, pset);
	v.max = get_max(is_pila, pset);
	while ((v.i = index_first_inversion(is_pila, pset)) != -1)
	{
		if (pile->data == v.min && get_last(is_pila, pset) == v.min2)
		{
			ope = is_pila ? RRA : RRB;
			add_one_ope(ope, pset);
			ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
			v.i = index_first_inversion(is_pila, pset);
		}
		cursor_by_index(&pile, v.i);

		if (v.i == pset->siza - 1 && (v.max == get_data(is_pila, v.i, pset) || v.min == get_data(is_pila, v.i + 1, pset)))
		{
			ope = is_pila ? RRA : RRB;
			add_one_ope(ope, pset);
		}
		else if (v.i == 1)
		{
			if ((pile->data == v.max && pile->next->data == v.min) || (pile->next->next && pile->next->data > pile->next->next->data))
				ope = is_pila ? RA : RB;
			else
				ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
		}
		else if (v.i == 2 && v.max == get_data(is_pila, v.i, pset) && get_last(is_pila, pset) > pile->prev->data
	&& pset->opes[ft_strlen(pset->opes) - 3] != 's')
		{
			to_firstlk(&pile);
			ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
			ope = is_pila ? RA : RB;
			add_one_ope(ope, pset);
		}
		else if (v.i > 1 && pile->next && pile->next->next && pile->data == v.max && pile->next->data == v.min2 && pile->next->next->data == v.min)
			mv_top(is_pila, v.i + 1, pset);
		else if (v.i == pset->siza - 2 && pile->next->next->data < pile->next->data)
			if (pile->next->next->data != v.min2)
				mv_top(is_pila, v.i + 1, pset);
			else
				mv_top(is_pila, v.i + 2, pset);
		else if (v.i > 1 && pile && pile->next)
		{
			to_firstlk(&pile);
			mv_top(is_pila, v.i, pset);
			ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
			if (pile->next->next && pile->next->next->data == v.min)
				mv_top(is_pila, get_index(is_pila, v.min, pset), pset);
			else
			{
				v.i = index_first_inversion(is_pila, pset);
				cursor_by_index(&pile, v.i);
				if (pile->next && pile->next->data == v.min)
				{
					to_firstlk(&pile);
					mv_top(is_pila, v.i + 1, pset);
				}
			}
		}
		to_firstlk(&pile);
	}
}

void	sort_small(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*ope;

	ope = is_pila ? SA : SB;
	pile = is_pila ? pset->pila : pset->pilb;
	if (countlk(pile) == 1)
		;
	else if (countlk(pile) == 2 && (is_pila && pile->data > pile->next->data) ||
	(!is_pila && pile->data < pile->next->data))
		add_one_ope(ope, pset);
	else if (countlk(pile) == 3)
		three_left_nsort(is_pila, pset);
	else if (countlk(pile) == 4)
		four_left_sort(&pile);
	else if (countlk(pile) == 5)
		five_left_sort(&pile);
}
