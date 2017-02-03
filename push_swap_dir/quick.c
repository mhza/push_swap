/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:29:33 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/03 20:18:00 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_pile(int is_pila, t_pset *pset)
{
	int		mid_val;
	int		count;
	char	*push;
	t_link	*pile;
	t_link	*temp;

	pile = is_pila ? pset->pila : pset->pilb;
	push = is_pila ? PB : PA;

	count = get_max_six_times_two(is_pila, pset) / 2;
	while (pile && (count = get_max_six_times_two(is_pila, pset)/ 2) >= 3)
	 {//printf("count %i\n", count);
		mid_val = find_midd(is_pila, pset);
		while (count)
		{
			if (pile->data < mid_val)
			{
				temp = pile->next;
				add_one_ope(push, pset);
				// if (push == PB && pset->pilb->next->data > pile->data)
				// 	add_one_ope(SB, pset);
				pile = temp;
				count--;
			}
			add_one_ope(RA, pset);

		}
		pset->siza = is_pila ? countlk(pset->pila) : pset->siza;
		pset->sizb = is_pila ? countlk(pset->pilb) - 1 : pset->sizb;
		// printf("siza A   %i  size B   %i\n",pset->siza, pset->sizb);
		// printf("get_max_six_times_two(is_pila, pset)/ 2)  %i\n", get_max_six_times_two(is_pila, pset)/ 2);
	// 	to_firstlk(&pile);
	}
}




// if (push == PB && pset->pilb->next->data > pile->data)
// 	add_one_ope(SB, pset);
