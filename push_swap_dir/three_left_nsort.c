/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_left_nsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:28:22 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/05 16:17:28 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_left_nsort(int is_pila, t_pset *pset)
{
	t_link	*npile;
	char	*swap;
	char	*rot;
	char	*rrot;
	int		d1;
	int		d2;
	int		d3;

	npile = !is_pila ? pset->pila : pset->pilb;
	d1 = npile->data;
	d2 = npile->next->data;
	d3 = npile->next->next->data;
	swap = !is_pila ? SA : SB;
	rot = !is_pila ? RA : RB;
	rrot = !is_pila ? RRA : RRB;
	if ((!is_pila && d1 < d2 && d1 < d3 && d2 > d3) || (is_pila && d1 > d2 && d1 > d3 && d2 < d3))
	{
		add_one_ope(rot, pset);
		add_one_ope(swap, pset);
		add_one_ope(rrot, pset);
	}
	else if ((!is_pila && d3 < d1 && d3 < d2) || (is_pila && d3 > d1 && d3 > d2))
	{
		if ((!is_pila && d1	> d2) || (is_pila && d1	< d2))
			add_one_ope(swap, pset);
		add_one_ope(rot, pset);
		add_one_ope(swap, pset);
		add_one_ope(rrot, pset);
		add_one_ope(swap, pset);
	}
	else if ((!is_pila && d2 < d1 && d2 < d3) || (is_pila && d2 > d1 && d2 > d3))
	{
		add_one_ope(swap, pset);
		if ((!is_pila && d1	> d3) || (is_pila && d1	< d3))
		{
			add_one_ope(rot, pset);
			add_one_ope(swap, pset);
			add_one_ope(rrot, pset);
		}
	}
	npile->pack = 1;
	npile->next->pack = 2;
	npile->next->next->pack = 3;
}
