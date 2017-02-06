/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_left_nsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:28:22 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 21:01:53 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_case_one(int is_pila, t_pset *pset)
{
	char	*swap;
	char	*rot;
	char	*rrot;

	swap = !is_pila ? SA : SB;
	rot = !is_pila ? RA : RB;
	rrot = !is_pila ? RRA : RRB;
	add_one_ope(rot, pset);
	add_one_ope(swap, pset);
	add_one_ope(rrot, pset);
}

static void	add_case_two(int is_pila, t_pset *pset, int d1, int d2)
{
	char	*swap;
	char	*rot;
	char	*rrot;

	swap = !is_pila ? SA : SB;
	rot = !is_pila ? RA : RB;
	rrot = !is_pila ? RRA : RRB;
	if ((!is_pila && d1 > d2) || (is_pila && d1 < d2))
		add_one_ope(swap, pset);
	add_one_ope(rot, pset);
	add_one_ope(swap, pset);
	add_one_ope(rrot, pset);
	add_one_ope(swap, pset);
}

static void	add_case_three(int is_pila, t_pset *pset, int d1, int d3)
{
	char	*swap;
	char	*rot;
	char	*rrot;

	swap = !is_pila ? SA : SB;
	rot = !is_pila ? RA : RB;
	rrot = !is_pila ? RRA : RRB;
	add_one_ope(swap, pset);
	if ((!is_pila && d1 > d3) || (is_pila && d1 < d3))
	{
		add_one_ope(rot, pset);
		add_one_ope(swap, pset);
		add_one_ope(rrot, pset);
	}
}

void		three_left_nsort(int is_pila, t_pset *pset)
{
	t_link	*npile;
	int		d1;
	int		d2;
	int		d3;

	npile = !is_pila ? pset->pila : pset->pilb;
	if (!npile)
		return ;
	d1 = npile->data;
	d2 = npile->next->data;
	d3 = npile->next->next->data;
	if ((!is_pila && d1 < d2 && d1 < d3 && d2 > d3) ||
	(is_pila && d1 > d2 && d1 > d3 && d2 < d3))
		add_case_one(is_pila, pset);
	else if ((!is_pila && d3 < d1 && d3 < d2) ||
	(is_pila && d3 > d1 && d3 > d2))
		add_case_two(is_pila, pset, d1, d2);
	else if ((!is_pila && d2 < d1 && d2 < d3) ||
	(is_pila && d2 > d1 && d2 > d3))
		add_case_three(is_pila, pset, d1, d3);
	npile->pack = 1;
	npile->next->pack = 2;
	npile->next->next->pack = 3;
}
