/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_getstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:59:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/04 23:28:58 by mhaziza          ###   ########.fr       */
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
	size = is_pila ? pset->siza : pset->sizb;
	i = -1;
	if (pset && index > size / 2 + 1)
	{
		ope = is_pila ? RRA : RRB;
		while (++i < size - index + 1)
		{
			pset->opes = ft_strreal(pset->opes, ope);
			ope_route(pset, ope);
		}
	}
	else
	{
		ope = is_pila ? RA : RB;
		while (++i < index - 1)
		{
			pset->opes = ft_strreal(pset->opes, ope);
			ope_route(pset, ope);
		}
	}
}

void	add_one_ope(char *ope, t_pset *pset)
{
	pset->opes = ft_strreal(pset->opes, ope);
	ope_route(pset, ope);
}
