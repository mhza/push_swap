/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:12:38 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/04 23:02:42 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void tests(t_pset *pset)
{
	// int		min;

	// printf("pset.siza %d\npset->pila : ", pset->siza);
	to_firstlk(&(pset->pila));
	print_data_next((pset->pila));
	// min = get_min((pset->pila));
	//  printf("lower data %d\n", min);
	// printf("get_index lower data %d\n", get_index((pset->pila), min));
	// printf("get_index first inversion %d\n", get_first_inversion((pset->pila)));
	// cursor_by_data(&(pset->pila), 5);
	to_firstlk(&(pset->pila));
	// cursor_by_index(&(pset->pila), get_index(1,22,pset ));
	// printf("cursor_to 22 ok ? %d\n", (pset->pila)->data);
	// to_firstlk(&(pset->pila));
	// printf("to_firstlk ? %d\n", (pset->pila)->data);
	simplest_case(1, pset);
	to_firstlk(&(pset->pila));
	print_data_next((pset->pila));
	// mv_top(1, 4, pset);
	// add_one_ope(SA,pset);
	// mv_top(1, get_index(1, pset, get_min(1, pset)), pset);
	// to_firstlk(&(pset->pila));
	// print_data_next((pset->pila));
	// printf("adresse pset.opes FIN %p : \n", pset->opes);
	// printf("pset->opes : %s\n", pset->opes);
}


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

	to_lastlk(&pset.pila);
	print_data_prev((pset.pila));
	to_firstlk(&pset.pila);
	// print_data_next((pset.pilb));
	// while (countlk((pset.pila)) > 6)
	split_pile(1, &pset);
	simplest_case(1, &pset);
	// printf("mid value haut pile B %i", get_min_max_mid(0, &pset));
	ft_putstr("APRES \n");

	// print_data_next((pset.pila));
	// print_data_next((pset.pilb));

	split_pack(0, &pset);

	to_firstlk(&pset.pila);
	to_firstlk(&pset.pilb);
	print_data_next((pset.pila));
	print_data_next((pset.pilb));
	//tests(&pset);
	free_link(&(pset.pila));
	free_link(&(pset.pilb));
	free(pset.opes);
	// int i = 1;
	// while (i == 1)
	// 	;
	return (1);
}
