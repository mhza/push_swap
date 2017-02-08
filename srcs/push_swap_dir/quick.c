/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:29:33 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 15:41:37 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_push(int is_pila, t_link **pile, t_pset *pset, int *count)
{
	char	*push;
	t_link	*temp;

	push = is_pila ? PB : PA;
	temp = (*pile)->next;
	add_one_ope(push, pset);
	(*pile)->pack = *count;
	*pile = temp;
	(*count)--;
}

void		split_pile(int is_pila, t_pset *pset)
{
	int		mid_val;
	int		count;
	int		count_cpy;
	char	*rot;
	t_link	*pile;

	pile = is_pila ? pset->pila : pset->pilb;
	rot = is_pila ? RA : RB;
	while (pile && (count = get_max_six_times_two(is_pila, pset) / 2) >= 3)
	{
		count_cpy = count;
		mid_val = find_midd(is_pila, pset);
		while (count)
		{
			if (pile && pile->data < mid_val)
				add_push(is_pila, &pile, pset, &count);
			else
				add_one_ope(rot, pset);
		}
		pset->siza = is_pila ? countlk(pset->pila) : pset->siza;
		pset->sizb = is_pila ? countlk(pset->pilb) : pset->sizb;
	}
}
