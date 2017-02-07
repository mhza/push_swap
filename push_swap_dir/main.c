/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:12:38 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 11:49:25 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pset	pset;
	int		siza;

	if (ac == 1 || !av[1] || (av[1] && !ft_strcmp(av[1], "")))
		return (0);
	if ((pset.opes = ft_strnew(sizeof(char))) == NULL)
		return (0);
	pset.opes[0] = 0;
	pset.pilb = NULL;

	if (!init_pile(&(pset.pila), ac, av, 0))
		return (ret_main(&(pset.pila), "Error\n", 0, 0));
 print_data_next(pset.pila);
pset.siza = countlk((pset.pila));
	siza = countlk((pset.pila));
	pset.mina = get_min(1, &pset);
	pset.maxa = get_max(1, &pset);
	if (siza < 6)
		sort_small(1, &pset);
	else
	{
		split_pile(1, &pset);
		sort_small(1, &pset);
		// if (siza > 12)
			split_pack(0, &pset);
		// else if (siza <= 8)
		// {
		// 	split_pack_rec(0, &pset);
		// 	print_data_next(pset.pila);
		// 	print_data_next(pset.pilb);
		// 	ft_putstr("\n\n");
		// 	pushall_isna(1, &pset);
		//
		// 	print_data_next(pset.pila);
		// 	print_data_next(pset.pilb);
		// 	ft_putstr("\n\n");
		// }
		// else if (siza <= 12)
		// {
		// 	split_pack_rec(0, &pset);
		// 	print_data_next(pset.pila);
		// 	print_data_next(pset.pilb);
		// 	ft_putstr("\n\n");
		// 	three_left_sort(1, &pset, 1);
		// 	pushall_isna(1, &pset);
		//
		// 	print_data_next(pset.pila);
		// 	print_data_next(pset.pilb);
		// 	ft_putstr("\n\n");
		// }
	}
	ft_putstr(pset.opes);
	// print_data_next(pset.pila);
	free_link(&(pset.pila));
	free_link(&(pset.pilb));
	free(pset.opes);
	// while (1)
	// 	;
	return (1);
}
// 2  1  8  5  7  10 3  9  4  6  11
