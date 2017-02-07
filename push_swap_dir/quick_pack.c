/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_pack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:38:47 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 14:43:03 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*push_rest(int is_pila, t_pset *pset, t_link *pile, t_count *cs)
{
	char	*ope;
	t_link	*temp;

	while (cs->count)
	{
		ope = is_pila ? RRA : RRB;
		add_one_ope(ope, pset);
		if (cs->sz_cpy != 6)
		{
			ope = is_pila ? PB : PA;
			temp = (pile)->next;
			add_one_ope(ope, pset);
			(pile)->pack = cs->sz;
			pile = temp;
		}
		if (pile)
			(pile)->pack = cs->sz;
		cs->sz--;
		cs->count--;
	}
	return (pile);
}

t_link	*push_mid(int is_pila, t_pset *pset, t_link *pile, t_count *cs)
{
	char	*ope;
	t_link	*temp;

	while (cs->sz_tmp && cs->sz_cpy > 3)
	{
		(cs->sz_tmp)--;
		if ((is_pila && cs->sz_cpy > 3 && (pile)->data < cs->mid_val) ||
		(!is_pila && ((cs->sz_cpy > 3 && (pile)->data >= cs->mid_val))))
		{
			ope = is_pila ? PB : PA;
			temp = (pile)->next;
			add_one_ope(ope, pset);
			(pile)->pack = cs->sz_cpy != 3 ? cs->sz - cs->sz_cpy / 2 : cs->sz;
			pile = temp;
			(cs->sz)--;
		}
		else
		{
			(cs->count)++;
			ope = is_pila ? RA : RB;
			add_one_ope(ope, pset);
		}
	}
	return (pile);
}

int		split_pack_rec(int is_pila, t_pset *pset)
{
	t_count	cs;
	t_link	*pile;

	pile = is_pila ? pset->pila : pset->pilb;
	if (!pile || index_first_inversion(is_pila, pset) == -1)
		return (-1);
	cs.sz = get_set_pack_size(is_pila, pset);
	cs.mid_val = get_min_max_mid(is_pila, pset);
	cs.sz_tmp = cs.sz;
	cs.sz_cpy = cs.sz;
	cs.count = 0;
	pile = push_mid(is_pila, pset, pile, &cs);
	pile = push_rest(is_pila, pset, pile, &cs);
	if (cs.sz_cpy <= 3)
		three_left_sort(is_pila, pset, 0);
	else if (cs.sz_cpy <= 6)
		three_left_sort(is_pila, pset, 1);
	return (cs.sz_cpy);
}

t_pset	*split_pack(int is_pila, t_pset *pset)
{
	if (countlk(pset->pilb) == 0 && index_first_inversion(1, pset) == -1)
		return (pset);
	else if ((countlk(pset->pilb) < 6 && countlk(pset->pila) < 9) ||
	(index_first_inversion(1, pset) == -1 &&
	index_first_inversion_dec(0, pset) == -1))
	{
		if (index_first_inversion(1, pset))
			sort_small(1, pset);
		if (index_first_inversion(0, pset))
			sort_small(0, pset);
		while (pset->pilb && countlk(pset->pilb))
			add_one_ope(PA, pset);
		return (pset);
	}
	if (split_pack_rec(is_pila, pset) < 6)
		return (split_pack(1 - is_pila, pset));
	return (split_pack(is_pila, pset));
}
