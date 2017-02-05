/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:12:38 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/05 21:15:54 by mhaziza          ###   ########.fr       */
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

	split_pile(1, &pset);
	simplest_case(1, &pset);
	split_pack(0, &pset);

	// ft_putstr("\n\nEND\n");
	// to_firstlk(&pset.pila);
	// to_firstlk(&pset.pilb);
	// print_data_next((pset.pila));
	// print_data_next((pset.pilb));
	ft_putstr(pset.opes);
	free_link(&(pset.pila));
	free_link(&(pset.pilb));
	free(pset.opes);

	while (1)
		;
	return (1);
}
