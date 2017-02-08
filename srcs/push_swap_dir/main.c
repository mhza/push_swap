/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:12:38 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 18:10:24 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_link(t_link **pile)
{
	if (pile)
	{
		while (*pile && (*pile)->next)
		{
			*pile = (*pile)->next;
			free((*pile)->prev);
		}
		if (*pile)
			free(*pile);
	}
}

static void	set_pset(t_pset *pset)
{
	pset->opes[0] = 0;
	pset->pilb = NULL;
	pset->siza = countlk((pset->pila));
	pset->mina = get_min(1, pset);
	pset->maxa = get_max(1, pset);
}

static int	if_error(t_pset *pset, char *str)
{
	write(2, str, ft_strlen(str));
	to_firstlk(&(pset->pila));
	free_link(&(pset->pila));
	return (0);
}

int			main(int ac, char **av)
{
	t_pset	pset;
	int		siza;

	if (ac == 1 || !av[1] || (av[1] && !ft_strcmp(av[1], "")))
		return (0);
	if ((pset.opes = ft_strnew(sizeof(char))) == NULL)
		return (0);
	if (!init_pile(&(pset.pila), ac, av, 0))
		return (if_error(&pset, ERROR));
	siza = countlk(pset.pila);
	set_pset(&pset);
	short_cut(1, &pset);
	if (siza > 1 && siza < 6 && index_first_inversion(1, &pset) != -1)
		under_five(1, &pset);
	else if (siza > 1 && index_first_inversion(1, &pset) != -1)
	{
		split_pile(1, &pset);
		under_five(1, &pset);
		split_pack(0, &pset);
	}
	ft_putstr(pset.opes);
	free_link(&(pset.pila));
	free_link(&(pset.pilb));
	free(pset.opes);
	return (1);
}
