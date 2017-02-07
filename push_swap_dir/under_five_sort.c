/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:47:43 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 15:37:55 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_left_sort(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*ope;

	pile = is_pila ? pset->pila : pset->pilb;
	mv_top(is_pila, get_index(is_pila, get_min(is_pila, pset), pset), pset);
	ope = is_pila ? PB : PA;
	add_one_ope(ope, pset);
	mv_top(is_pila, get_index(is_pila, get_min(is_pila, pset), pset), pset);
	ope = is_pila ? PB : PA;
	add_one_ope(ope, pset);
	three_left_nsort(1 - is_pila, pset);
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
	ope = is_pila ? PB : PA;
	add_one_ope(ope, pset);
	three_left_nsort(1 - is_pila, pset);
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
		;
	else if (countlk(pile) == 2 && ((is_pila && pile->data > pile->next->data)
	|| (!is_pila && pile->data < pile->next->data)))
		add_one_ope(ope, pset);
	else if (countlk(pile) == 3)
		three_left_nsort(1 - is_pila, pset);
	else if (countlk(pile) == 4)
		four_left_sort(is_pila, pset);
	else if (countlk(pile) == 5)
		five_left_sort(is_pila, pset);
}
