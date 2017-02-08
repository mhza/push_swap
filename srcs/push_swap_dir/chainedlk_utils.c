/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainedlk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:24:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 15:40:33 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cursor_by_index(t_link **alk, int index)
{
	while (alk && *alk && index > 1)
	{
		*alk = (*alk)->next;
		index--;
	}
}

int		get_index(int is_pila, int data, t_pset *pset)
{
	int		count;
	t_link	*alk;

	count = 1;
	alk = is_pila ? pset->pila : pset->pilb;
	while (alk && alk->data != data)
	{
		count++;
		alk = alk->next;
	}
	return (count);
}

int		get_min(int is_pila, t_pset *pset)
{
	int		min;
	t_link	*alk;

	alk = is_pila ? pset->pila : pset->pilb;
	min = 0;
	if (alk)
		min = alk->data;
	while (alk && alk->next)
	{
		if (alk->data < min)
			min = alk->data;
		alk = alk->next;
	}
	if (alk && alk->data < min)
		min = alk->data;
	return (min);
}

int		get_min2(int is_pila, t_pset *pset)
{
	int		min;
	int		min2;
	t_link	*alk;

	alk = is_pila ? pset->pila : pset->pilb;
	to_firstlk(&alk);
	min = get_min(is_pila, pset);
	min2 = alk->data;
	min2 = min2 == min ? min2 + 1 : min2;
	while (alk && alk->next)
	{
		if (alk->data < min2 && alk->data != min)
			min2 = alk->data;
		alk = alk->next;
	}
	if (alk && alk->data < min2 && alk->data != min)
		min2 = alk->data;
	return (min2);
}

int		get_max(int is_pila, t_pset *pset)
{
	int		max;
	t_link	*alk;

	alk = is_pila ? pset->pila : pset->pilb;
	max = 0;
	if (alk)
		max = alk->data;
	while (alk && alk->next)
	{
		if (alk->data > max)
			max = alk->data;
		alk = alk->next;
	}
	if (alk && alk->data > max)
		max = alk->data;
	return (max);
}
