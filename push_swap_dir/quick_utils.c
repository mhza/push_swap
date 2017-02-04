/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:41:57 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/04 20:43:03 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

int			get_max_six_times_two(int is_pila, t_pset *pset)
{
	int	i;
	int size;

	size = is_pila ? pset->siza : pset->sizb;
	i = 3;
	while (i * 2 <= size)
		i *= 2;
	return (i);
}

static int	count_lk_under(t_link *pile, int min, int max)
{
	int i;

	i = 0;
	while (pile && (!pile->pack || pile->pack != 1 || !pile->prev))
	{
		if (pile->data < (min + max) / 2)
			i++;
		pile = pile->next;
	}
	return (i);
}

int			find_mid_pile(t_link *pile, int size, int min, int max)
{
	if (min == max || max - min == 1)
		return (max);
	if (count_lk_under(pile, min, max) < size / 2)
		return (find_mid_pile(pile, size, (min + max) / 2, max));
	else
		return (find_mid_pile(pile, size, min, (min + max) / 2));
}

int		find_midd(int is_pila, t_pset *pset)
{
	int	i;

	i = get_max_six_times_two(is_pila, pset);
	if (is_pila)
		return (find_mid_pile(pset->pila, i, pset->mina, pset->maxa));
	return (find_mid_pile(pset->pilb, i, pset->minb, pset->maxb));
	// if (is_pila)
	// 	return (find_mid_pile(pset->pila, size, pset->mina, pset->maxa));
	// return (find_mid_pile(pset->pilb, size, pset->minb, pset->maxb));
}


// la mid value retournee separe la pile en : min -> mid et mid -> max + (max - i)
// ==> reste les max - i plus grandes valeurs a trier
