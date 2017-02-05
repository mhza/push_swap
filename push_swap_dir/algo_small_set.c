/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:47:43 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/05 17:28:57 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplest_case(int is_pila, t_pset *pset)
{
	int		index;
	int		min;
	int		min2;
	int		max;
	t_link	*pile;
	char	*ope;

	pile = is_pila ? pset->pila : pset->pilb;
	if (countlk(pile) == 1)
		return ;
	min = get_min(is_pila, pset);
	min2 = get_min2(is_pila, pset);
	max = get_max(is_pila, pset);
	while ((index = index_first_inversion(is_pila, pset)) != -1)
	{
		if (pile->data == min && get_last(is_pila, pset) == min2)
		{
			ope = is_pila ? RRA : RRB;
			add_one_ope(ope, pset);
			ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
			index = index_first_inversion(is_pila, pset);
		}
		cursor_by_index(&pile, index);

		if (index == pset->siza - 1 && (max == get_data(is_pila, index, pset) || min == get_data(is_pila, index + 1, pset)))
		{
			ope = is_pila ? RRA : RRB;
			add_one_ope(ope, pset);
		}
		else if (index == 1)
		{
			if ((pile->data == max && pile->next->data == min) || (pile->next->next && pile->next->data > pile->next->next->data))
				ope = is_pila ? RA : RB;
			else
				ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
		}
		else if (index == 2 && max == get_data(is_pila, index, pset) && get_last(is_pila, pset) > pile->prev->data
	&& pset->opes[ft_strlen(pset->opes) - 3] != 's')
		{
			to_firstlk(&pile);
			ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
			ope = is_pila ? RA : RB;
			add_one_ope(ope, pset);
		}
		else if (index > 1 && pile->next && pile->next->next && pile->data == max && pile->next->data == min2 && pile->next->next->data == min)
			mv_top(is_pila, index + 1, pset);
		else if (index == pset->siza - 2  && pile->next->next->data < pile->next->data)
			if (pile->next->next->data != min2)
				mv_top(is_pila, index + 1, pset);
			else
				mv_top(is_pila, index + 2, pset);
		else if (index > 1 && pile && pile->next)
		{
			to_firstlk(&pile);
			mv_top(is_pila, index, pset);
			// if ( pile->prev->data < pile->next->data)
			ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
			if (pile->next->next && pile->next->next->data == min)
				mv_top(is_pila, get_index(is_pila, min, pset), pset);
			else
			{
				index = index_first_inversion(is_pila, pset);
				cursor_by_index(&pile, index);
				if (pile->next && pile->next->data == min)
				{
					to_firstlk(&pile);
					mv_top(is_pila, index + 1, pset);
				}
			}
		}
		to_firstlk(&pile);
	}
}
