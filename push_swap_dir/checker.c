/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:22:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/02 14:39:46 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ope_route(int is_pila, t_pset *pset, char *cmd)
{
	if ((!ft_strcmp(cmd, SA) || !ft_strcmp(cmd, SS)))
		swap(&(pset->pila));
	if ((!ft_strcmp(cmd, SB) || !ft_strcmp(cmd, SS)))
		swap(&(pset->pilb));
	if (!ft_strcmp(cmd, PB))
		push(&(pset->pila), &(pset->pilb));
	if (!ft_strcmp(cmd, PA))
		push(&(pset->pilb), &(pset->pila));
	if ((!ft_strcmp(cmd, RA) || !ft_strcmp(cmd, RR)))
		rotate(&(pset->pila));
	if ((!ft_strcmp(cmd, RB) || !ft_strcmp(cmd, RR)))
		rotate(&(pset->pilb));
	if ((!ft_strcmp(cmd, RRA) || !ft_strcmp(cmd, RRR)))
		rrotate(&(pset->pila));
	if ((!ft_strcmp(cmd, RRB) || !ft_strcmp(cmd, RRR)))
		rrotate(&(pset->pilb));
}
