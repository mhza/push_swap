/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 23:30:50 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/09 11:44:58 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	only_case_one(int is_pila, t_pset *pset)
{
	char	*swap;
	char	*rot;
	char	*rrot;

	swap = is_pila ? SA : SB;
	rot = is_pila ? RA : RB;
	rrot = is_pila ? RRA : RRB;
	add_one_ope(rot, pset);
	add_one_ope(swap, pset);
	add_one_ope(rrot, pset);
}

static void	only_case_two(int is_pila, t_pset *pset, int d1, int d2)
{
	char	*swap;
	char	*rot;
	char	*rrot;

	swap = is_pila ? SA : SB;
	rot = is_pila ? RA : RB;
	rrot = is_pila ? RRA : RRB;
	if ((!is_pila && d1 > d2) || (is_pila && d1 < d2))
		add_one_ope(rrot, pset);
	else
	{
		add_one_ope(rot, pset);
		add_one_ope(swap, pset);
	}
}

static void	only_case_three(int is_pila, t_pset *pset, int d1, int d3)
{
	char	*swap;
	char	*rot;
	char	*rrot;

	swap = is_pila ? SA : SB;
	rot = is_pila ? RA : RB;
	rrot = is_pila ? RRA : RRB;
	if ((is_pila && d1 > d3) || (!is_pila && d1 < d3))
	{
		add_one_ope(rot, pset);
	}
	else
	{
		add_one_ope(rrot, pset);
		add_one_ope(swap, pset);
		add_one_ope(rrot, pset);
	}
}

void		only_three(int is_pila, t_pset *pset)
{
	t_link	*pile;
	int		d1;
	int		d2;
	int		d3;

	pile = is_pila ? pset->pila : pset->pilb;
	if (!pile)
		return ;
	d1 = pile->data;
	d2 = pile->next->data;
	d3 = pile->next->next->data;
	if ((is_pila && d1 < d2 && d1 < d3 && d2 > d3) ||
	(!is_pila && d1 > d2 && d1 > d3 && d2 < d3))
		only_case_one(is_pila, pset);
	else if ((is_pila && d3 < d1 && d3 < d2) ||
	(!is_pila && d3 > d1 && d3 > d2))
		only_case_two(is_pila, pset, d1, d2);
	else if ((is_pila && d2 < d1 && d2 < d3) ||
	(!is_pila && d2 > d1 && d2 > d3))
		only_case_three(is_pila, pset, d1, d3);
}
