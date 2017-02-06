/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:12:38 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 17:04:33 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pset	pset;

	if (ac == 1 || !av[1] || (av[1] && !ft_strcmp(av[1], "")))
		return (0);
	if ((pset.opes = ft_strnew(sizeof(char))) == NULL)
		return (0);
	pset.opes[0] = 0;
	pset.pilb = NULL;
	if (!init_pile(&(pset.pila), ac, av, 0))
		return (ret_main(&(pset.pila), "Error\n", 0, 0));
	pset.siza = countlk((pset.pila));
	pset.mina = get_min(1, &pset);
	pset.maxa = get_max(1, &pset);
	print_data_next(pset.pila);
	if (pset.siza < 6)
		simplest_case(1, &pset);
	else
	{
		split_pile(1, &pset);
		simplest_case(1, &pset);
		split_pack(0, &pset);
	}
	ft_putstr(pset.opes);
	print_data_next(pset.pila);
	free_link(&(pset.pila));
	free_link(&(pset.pilb));
	free(pset.opes);
	// while (1)
	// 	;
	return (1);
}
