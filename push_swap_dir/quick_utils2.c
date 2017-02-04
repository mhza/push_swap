/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:38:47 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/04 23:45:10 by mhaziza          ###   ########.fr       */
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

void 	sort_six(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*ope;
	int d1;
	int d2;
	int d3;

	pile = is_pila ? pset->pila : pset->pilb;
	d1 = pile->data;
	d2 = pile->next->data;
	d3 = pile->next->next->data;
	if (d1 > d2 && d1 > d3)
	{
		if (d2 > d3)
		{
			add_one_ope(PB, pset);
			add_one_ope(PB, pset);
			add_one_ope(PB, pset);
		}
		else
		{
			add_one_ope(PB, pset);
			add_one_ope(SA, pset);
			add_one_ope(PB, pset);
			add_one_ope(PB, pset);
		}
	}
	else if (d3 > d1 && d3 > d2)
	{
		if (d1 > d2)
		{
			add_one_ope(SA, pset);
		}
		add_one_ope(RB, pset);
		ope = is_pila ? SA : SB;
		add_one_ope(SB, pset);
		add_one_ope(PB, pset);
		add_one_ope(PB, pset);
		ope = is_pila ? RRB : RRA;
		add_one_ope(PB, pset);
		ope = is_pila ? PB : PA;
		add_one_ope(PB, pset);
	}
	else
	{

		ope = is_pila ? SA : SB;
		add_one_ope(PB, pset);
		ope = is_pila ? PB : PA;
		add_one_ope(PB, pset);
		if (d1 < d3)
		{
			ope = is_pila ? SA : SB;
			add_one_ope(PB, pset);
		}
		ope = is_pila ? PB : PA;
		add_one_ope(PB, pset);
		ope = is_pila ? PB : PA;
		add_one_ope(PB, pset);
	}
}

t_pset *split_pack(int is_pila, t_pset *pset)
{
	int		mid_val;
	int		count;
	int		size;
	int		size_tmp;
	int		size_cpy;
	char	*ope;
	t_link	*pile;
	t_link	*temp;

// if (pset->pila && countlk(pset->pila) > 5 && index_first_inversion(1, pset) == -1)
// {ft_putstr("yo");ft_putnbr(countlk(pset->pila));	return (pset);}

	pile = is_pila ? pset->pila : pset->pilb;
	// if (size == 3)
	// {
	// 	ope = is_pila ? PB : PA;
	// 	add_one_ope(ope, pset);
	// 	ope = is_pila ? PB : PA;
	// 	add_one_ope(ope, pset);
	// 	ope = is_pila ? PB : PA;
	// 	add_one_ope(ope, pset);
	// 	size = get_set_pack_size(is_pila, pset);
	// }
	while (pile && (size = get_set_pack_size(is_pila, pset)) > 3)
	{
		// to_firstlk(&pile);
		mid_val = get_min_max_mid(is_pila, pset);
		// printf("ENTRE ");
		// printf("pile->data %i pile->pack %i pile->next->pack %i mid_val %i size %i\n", pile->data, pile->pack, pile->next->pack, mid_val, size);
		size_tmp = size;
		size_cpy = size;
		count = 0;
		while (size_tmp)
		{
			size_tmp--;
			// printf("IN pile->prev %p\npile->data %i pile->pack %i \npile->next->data %i pile->next->pack %i mid_val %i\n", pile->prev, pile->data, pile->pack, pile->next->data, pile->next->pack, mid_val);
			if ((is_pila && pile->data < mid_val) || (!is_pila && ((size_cpy == 3 && pile->data > mid_val) || (size_cpy >3 && pile->data >= mid_val))))
			{
				ope = is_pila ? PB : PA;
				temp = pile->next;
				add_one_ope(ope, pset);
				pile->pack = size;
				pile = temp;
				size--;
				// ft_putstr("PA \n");
				// print_data_next((pset->pila));
				// print_data_next((pset->pilb));
			}
			else
			{
				count++;
				ope = is_pila ? RA : RB;
				add_one_ope(ope, pset);
				// ft_putstr("RB \n");
				// print_data_next((pset->pila));
				// print_data_next((pset->pilb));
			}
		}
		// printf(">>>>> COUNT %i\n", count);
		while (count)
		{
			ope = is_pila ? RRA : RRB;
			add_one_ope(ope, pset);
			ope = is_pila ? PB : PA;
			temp = pile->next;
			add_one_ope(ope, pset);
			pile->pack = size;
			pile = temp;
			size--;
			count--;
			// ft_putstr("RRB + PB \n");
			// print_data_next((pset->pila));
			// print_data_next((pset->pilb));
		}

			// printf("get_set_pack_size %i\n", get_set_pack_size(is_pila, pset));
		// pile = is_pila ? pset->pila : pset->pilb;

	}
	printf("END\n");
	print_data_next((pset->pila));
	print_data_next((pset->pilb));
	// if (is_pila)
	// 	return (split_pack(0, pset));
	// return (split_pack(1, pset));
	return (NULL);
}
