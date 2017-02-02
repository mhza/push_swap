/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:12:38 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/02 16:41:10 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void tests(t_pset *pset)
{
	// int		min;

	// printf("pset.siza %d\npset->pila : ", pset->siza);
	to_firstlk(&(pset->pila));
	 print_data_next((pset->pila));
	// min = get_minlk((pset->pila));
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
	// mv_top(1, get_index(1, pset, get_minlk(1, pset)), pset);
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
	if ((pset.pilb = ft_memalloc(sizeof(t_link))) == NULL)
		return (0);
	if (!init_pile(&(pset.pila), ac, av, 0))
		return (ret_main(&(pset.pila), "Error\n", 0, 0));
	pset.siza = countlk((pset.pila));
	pset.sizb = -1;
	// printf("adresse pset.opes DEBUT  %p : \n", pset.opes);
	// printf("adresse pset.pila DEBUT  %p : \n", pset.pila);
	// printf("adresse pset.pilb DEBUT  %p : \n", pset.pilb);

	tests(&pset);
	free_link(&(pset.pila));
	free_link(&(pset.pilb));
	ft_putstr(pset.opes);
	free(pset.opes);
	// int i = 1;
	// while (i == 1)
	// 	;
 // 	ft_printf("operation %s\n", put_top(pile));
	return (1);
}
