/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:29:33 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/05 18:37:39 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_pile(int is_pila, t_pset *pset)
{
	int		mid_val;
	int		count;
	int		count_cpy;
	char	*push;
	char	*rot;
	t_link	*pile;
	t_link	*temp;

	pile = is_pila ? pset->pila : pset->pilb;
	push = is_pila ? PB : PA;
	rot = is_pila ? RA : RB;
	// ft_putstr("\ncount   total");
	// ft_putnbr(countlk(pile));
	while (pile && (count = get_max_six_times_two(is_pila, pset) / 2) >= 3 )
	{//ft_putstr(">>>>> SHIT\n");

	// ft_putstr("\ncount   ");
	// ft_putnbr(count);
	// ft_putstr("\nA   ");
	// print_data_next((pset->pila));
	// ft_putstr("B   ");
	// print_data_next((pset->pilb));
		count_cpy= count;
		mid_val = find_midd(is_pila, pset);
		while (count)
		{//ft_putstr(">>>>> SHIT count\n");
			if (pile && pile->data < mid_val)
			{
				temp = pile->next;
				add_one_ope(push, pset);
				pile->pack = count;
				// if (push == PB && pset->pilb !=NULL && pset->pilb->next->data > pile->data)
				// 	add_one_ope(SB, pset);
				pile = temp;
				count--;
			}
			else
				add_one_ope(rot, pset);


		}
		//ft_putstr("<<<<< SHIT count\n");
		pset->siza = is_pila? countlk(pset->pila) : pset->siza;
		pset->sizb = is_pila? countlk(pset->pilb) : pset->sizb;
	//	ft_putstr("<<<<< SHIT pset->siza b\n");
		// printf("siza A   %i  size B   %i\n",pset->siza, pset->sizb);
		// printf("get_max_six_times_two(is_pila, pset)/ 2)  %i\n", get_max_six_times_two(is_pila, pset)/ 2);
		// to_firstlk(&pile);
		// if (count_cpy == 3 && pile && countlk(pile))
		// 	three_left_sort(!is_pila, pset);
	//	ft_putstr("<<<<< SHIT if (count_cpy == 3)\n");
	}
}




// if (push == PB && pset->pilb->next->data > pile->data)
// 	add_one_ope(SB, pset);
