/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_left_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 12:02:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 15:34:41 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_case_one(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*push;
	char	*swap;

	pile = is_pila ? pset->pila : pset->pilb;
	push = is_pila ? PB : PA;
	swap = is_pila ? SA : SB;
	if ((!is_pila && pile->next->data > pile->next->next->data) ||
	(is_pila && pile->next->data < pile->next->next->data))
	{
		add_one_ope(push, pset);
		add_one_ope(push, pset);
		add_one_ope(push, pset);
	}
	else
	{
		add_one_ope(push, pset);
		add_one_ope(swap, pset);
		add_one_ope(push, pset);
		add_one_ope(push, pset);
	}
}

static void	if_case_two(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*push;
	char	*swap;
	char	*rot;

	pile = is_pila ? pset->pila : pset->pilb;
	push = is_pila ? PB : PA;
	swap = is_pila ? SA : SB;
	rot = is_pila ? RA : RB;
	if ((!is_pila && pile->data > pile->next->data) ||
	(is_pila && pile->data < pile->next->data))
		add_one_ope(swap, pset);
	add_one_ope(rot, pset);
	add_one_ope(swap, pset);
	add_one_ope(push, pset);
	add_one_ope(push, pset);
	rot = is_pila ? RRA : RRB;
	add_one_ope(rot, pset);
	add_one_ope(push, pset);
}

static void	if_case_three(int is_pila, t_pset *pset)
{
	t_link	*pile;
	t_link	*tmp;
	char	*push;
	char	*swap;

	pile = is_pila ? pset->pila : pset->pilb;
	push = is_pila ? PB : PA;
	swap = is_pila ? SA : SB;
	add_one_ope(swap, pset);
	tmp = pile->next;
	add_one_ope(push, pset);
	pile = tmp;
	if ((!is_pila && pile->data < pile->next->data) ||
	(is_pila && pile->data > pile->next->data))
		add_one_ope(swap, pset);
	add_one_ope(push, pset);
	add_one_ope(push, pset);
}

void		three_left_sort(int is_pila, t_pset *pset, int nsort)
{
	t_link	*pile;
	t_link	*npile;
	int		d;
	int		d2;
	int		d3;

	pile = is_pila ? pset->pila : pset->pilb;
	if (!pile)
		return ;
	npile = !is_pila ? pset->pila : pset->pilb;
	d = pile->data;
	d2 = pile->next->data;
	d3 = pile->next->next->data;
	if (npile && nsort)
		three_left_nsort(is_pila, pset);
	if ((!is_pila && d > d2 && d > d3) || (is_pila && d < d2 && d < d3))
		if_case_one(is_pila, pset);
	else if ((!is_pila && d3 > d && d3 > d2) || (is_pila && d3 < d && d3 < d2))
		if_case_two(is_pila, pset);
	else if ((!is_pila && d2 > d && d2 > d3) || (is_pila && d2 < d && d2 < d3))
		if_case_three(is_pila, pset);
	npile->prev->prev->prev->pack = 1;
	npile->prev->prev->pack = 2;
	npile->prev->pack = 3;
}
