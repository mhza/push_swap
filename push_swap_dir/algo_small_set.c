/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:47:43 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/02 17:41:19 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplest_case(int is_pila, t_pset *pset)
{
	int		index;
	int		min;
	t_link	*pile;
	char	*ope;

	pile = is_pila ? pset->pila : pset->pilb;
	min = get_minlk(is_pila, pset);
	while ((index = index_first_inversion(pile)) != -1)
	{
		cursor_by_index(&pile, index);
		if (index > 1 && pile && pile->next)
		{
			to_firstlk(&pile);
			mv_top(is_pila, index, pset);
			ope = is_pila ? SA : SB;
			add_one_ope(ope, pset);
			if (pile->next->next && pile->next->next->data == min)
				mv_top(is_pila, get_index(is_pila, min, pset), pset);
			else
			{
				index = index_first_inversion(pile);
				cursor_by_index(&pile, index);
				if (pile->next && pile->next->data == min)
				{
					to_firstlk(&pile);
					mv_top(is_pila, index + 1, pset);
				}
			}
		}
		else if (index == 1)
		{
			ope = is_pila ? RA : RB;
			add_one_ope(ope, pset);
		}
		else if (index == pset->siza - 1 && min == get_data(is_pila, index + 1, pset))
		{
			ope = is_pila ? RRA : RRB;
			add_one_ope(ope, pset);
		}
		to_firstlk(&pile);
	}
}
