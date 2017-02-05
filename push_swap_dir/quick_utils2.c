/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:38:47 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/05 19:48:24 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_set_pack_size(int is_pila, t_pset *pset)
{
	t_link  *pile;
	int	i;

	i= 0;
	pile = is_pila ? pset->pila : pset->pilb;
	while (pile && (pile->pack != 1 || !pile->prev))
	{	pile = pile->next;i++;}
	pset->siza = is_pila ? i : pset->siza;
	pset->sizb = is_pila ? i: pset->sizb;
	return (i);
}

int	get_min_max_mid(int is_pila, t_pset *pset)
{
	int	min;
	int max;
	int mid_val;
	int i;
	t_link  *pile;

	i = 0;
	pile = is_pila ? pset->pila : pset->pilb;
	min = pile->data;
	max = min;
	mid_val = min;
	while (pile && (pile->pack != 1 || !pile->prev))
	{
		i++;
		if (pile->data < min)
			min = pile->data;
		if (pile->data > max)
			max = pile->data;
		pile = pile->next;
	}
	if (is_pila)
		mid_val = find_mid_pile(pset->pila, i, min, max);
	else
		mid_val = find_mid_pile(pset->pilb, i, min, max);
	return (mid_val);
}

int 	split_pack_rec(int is_pila, t_pset *pset)
{
	int		mid_val;
	int		count;
	int		size;
	int		size_tmp;
	int		size_cpy;
	char	*ope;
	t_link	*pile;
	t_link	*temp;

	pile = is_pila ? pset->pila : pset->pilb;
	if (!pile || index_first_inversion(is_pila, pset) == -1)
		return (-1);
	size = get_set_pack_size(is_pila, pset);
	mid_val = get_min_max_mid(is_pila, pset);
	size_tmp = size;
	size_cpy = size;
	count = 0;
	while (size_tmp && size_cpy > 3)
	{
		size_tmp--;
		if ((is_pila && size_cpy > 3 && pile->data < mid_val) || (!is_pila && ((size_cpy > 3 && pile->data >= mid_val))))
		{
			ope = is_pila ? PB : PA;
			temp = pile->next;
			add_one_ope(ope, pset);
			pile->pack = size_cpy != 3 ? size - size_cpy / 2 : size;
			pile = temp;
			size--;
		}
		else
		{
			count++;
			ope = is_pila ? RA : RB;
			add_one_ope(ope, pset);
		}
	}
	while (count)
	{
		ope = is_pila ? RRA : RRB;
		add_one_ope(ope, pset);
		if (size_cpy != 6)
		{
			ope = is_pila ? PB : PA;
			temp = pile->next;
			add_one_ope(ope, pset);
			pile->pack = size;
			pile = temp;
		}
		if (pile)
			pile->pack = size;

		size--;
		count--;
	}
	if (size_cpy == 6)
		three_left_sort(is_pila, pset, 1);
	if (size_cpy == 3)
		three_left_sort(is_pila, pset, 0);
	return (size_cpy);
}

t_pset	*split_pack(int is_pila, t_pset *pset)
{
	if (index_first_inversion(1, pset) == -1 && countlk(pset->pilb) == 0)
		return (pset);
	else if (index_first_inversion(1, pset) == -1 && index_first_inversion_dec(0, pset) == -1)
	{
		while(pset->pilb && countlk(pset->pilb))
			add_one_ope(PA, pset);
		return (pset);
	}
	if (split_pack_rec(is_pila, pset) < 6)
		return (split_pack(1 - is_pila, pset));
	return (split_pack(is_pila, pset));
}
