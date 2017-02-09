/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:47:43 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/09 12:24:54 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_cut(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*ope;

	pile = is_pila ? pset->pila : pset->pilb;
	if (pile->data == get_min2(is_pila, pset) && pile->next &&
		pile->next->data == get_min(is_pila, pset))
	{
		ope = is_pila ? SA : SB;
		add_one_ope(ope, pset);
	}
}

void	five_left_sort(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*ope;

	pile = is_pila ? pset->pila : pset->pilb;
	mv_top(is_pila, get_index(is_pila, get_min(is_pila, pset), pset), pset);
	if (index_first_inversion(is_pila, pset) == -1)
		return ;
	ope = is_pila ? PB : PA;
	add_one_ope(ope, pset);
	mv_top(is_pila, get_index(is_pila, get_min(is_pila, pset), pset), pset);
	ope = is_pila ? PB : PA;
	add_one_ope(ope, pset);
	only_three(is_pila, pset);
	ope = !is_pila ? PB : PA;
	add_one_ope(ope, pset);
	ope = !is_pila ? PB : PA;
	add_one_ope(ope, pset);
}

void	four_left_sort(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*ope;

	pile = is_pila ? pset->pila : pset->pilb;
	mv_top(is_pila, get_index(is_pila, get_min(is_pila, pset), pset), pset);
	if (index_first_inversion(is_pila, pset) == -1)
		return ;
	ope = is_pila ? PB : PA;
	add_one_ope(ope, pset);
	only_three(is_pila, pset);
	ope = !is_pila ? PB : PA;
	add_one_ope(ope, pset);
}

void	under_five(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*ope;

	ope = is_pila ? SA : SB;
	pile = is_pila ? pset->pila : pset->pilb;
	if (countlk(pile) == 1)
		return ;
	short_cut(is_pila, pset);
	if (index_first_inversion(is_pila, pset) == -1)
		return ;
	else if (countlk(pile) == 2 && ((is_pila && pile->data > pile->next->data)
	|| (!is_pila && pile->data < pile->next->data)))
		add_one_ope(ope, pset);
	else if (countlk(pile) == 3)
		only_three(is_pila, pset);
	else if (countlk(pile) == 4)
		four_left_sort(is_pila, pset);
	else if (countlk(pile) == 5)
		five_left_sort(is_pila, pset);
}
