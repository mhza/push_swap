/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_getstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:59:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 09:14:04 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_top(int is_pila, int index, t_pset *pset)
{
	int		size;
	int		i;
	char	*ope;

	if (!pset || index < 0)
		return ;
	size = is_pila ? countlk(pset->pila) : countlk(pset->pilb);
	i = -1;
	if (pset && index > size / 2 + 1)
	{
		ope = is_pila ? RRA : RRB;
		while (++i < size - index + 1)
			add_one_ope(ope, pset);
	}
	else
	{
		ope = is_pila ? RA : RB;
		while (++i < index - 1)
			add_one_ope(ope, pset);
	}
}

void	pushall_isna(int is_pila, t_pset *pset)
{
	char	*ope;
	t_link	*pile;
	int		size;

	ope = is_pila ? PA : PB;
	pile = !is_pila ? pset->pila : pset->pilb;
	size = countlk(pile);
	while (size)
	{
		add_one_ope(ope, pset);
		size--;
	}
}

void	add_one_ope(char *ope, t_pset *pset)
{
	pset->opes = ft_strreal(pset->opes, ope);
	ope_route(pset, ope);
}
