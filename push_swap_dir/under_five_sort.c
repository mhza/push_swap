/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:47:43 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 22:43:33 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_left_sort(int is_pila, t_pset *pset)
{
	t_link	*pile;
	t_link	*tmp;
	char	*ope;
	int		min;
	int		min2;

	min = get_min(is_pila, pset);
	// printf("min %i et min2 %i\n", min, min2);
	// printf("index min %i et index min2 %i\n", get_index(is_pila, min, pset), get_index(is_pila, min2, pset));
	pile = is_pila ? pset->pila : pset->pilb;
	tmp = pile->next;
	mv_top(is_pila, get_index(is_pila, min, pset), pset);
	ope = is_pila ? PB : PA;
	add_one_ope(ope, pset);
	pile = tmp;
	tmp = pile->next;
	print_data_next(pset->pila);
	print_data_next(pset->pilb);
	ft_putstr("\n\n");
	min2 = get_min(is_pila, pset);

	mv_top(is_pila, get_index(is_pila, min2, pset), pset);
	ope = is_pila ? PB : PA;
	pile = tmp;
	add_one_ope(ope, pset);
	print_data_next(pset->pila);
	print_data_next(pset->pilb);
	ft_putstr("\n\n");
	three_left_nsort(1 - is_pila, pset);
	tmp = pile->next;
	ope = !is_pila ? PB : PA;
	add_one_ope(ope, pset);
	pile = tmp;
	ope = !is_pila ? PB : PA;
	add_one_ope(ope, pset);
	print_data_next(pset->pila);
	print_data_next(pset->pilb);
	ft_putstr("=====\n\n");
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

void	sort_small(int is_pila, t_pset *pset)
{
	t_link	*pile;
	char	*ope;
	int		size;

	ope = is_pila ? SA : SB;
	pile = is_pila ? pset->pila : pset->pilb;
	size = countlk(pile);
	if (size == 1)
		;
	else if (size == 2 && ((is_pila && pile->data > pile->next->data)
	|| (!is_pila && pile->data < pile->next->data)))
		add_one_ope(ope, pset);
	else if (size == 3)
		three_left_nsort(1 - is_pila, pset);
	else if (size == 4)
		four_left_sort(is_pila, pset);
	else if (size == 5)
		five_left_sort(is_pila, pset);
}
