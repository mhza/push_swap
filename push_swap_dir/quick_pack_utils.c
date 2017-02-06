/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_pack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:22:46 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 15:29:32 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_set_pack_size(int is_pila, t_pset *pset)
{
	t_link	*pile;
	int		i;

	i = 0;
	pile = is_pila ? pset->pila : pset->pilb;
	while (pile && (pile->pack != 1 || !pile->prev))
	{
		pile = pile->next;
		i++;
	}
	pset->siza = is_pila ? i : pset->siza;
	pset->sizb = is_pila ? i : pset->sizb;
	return (i);
}

int	get_min_max_mid(int is_pila, t_pset *pset)
{
	int		min;
	int		max;
	int		mid_val;
	int		i;
	t_link	*pile;

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
