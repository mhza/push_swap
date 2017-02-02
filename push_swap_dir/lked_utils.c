/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lked_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:24:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/02 17:55:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  cursor_by_data(t_link **alk, int data)
{
	while (alk && *alk && (*alk)->data != data)
		*alk = (*alk)->next;
}

void	cursor_by_index(t_link **alk, int index)
{
	while (alk && *alk && index > 1)
	{
		*alk = (*alk)->next;
		index--;
	}
}

int		get_minlk(int is_pila, t_pset *pset)
{
	int min;
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

int		get_max(int is_pila, t_pset *pset)
{
	int max;
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
int		get_data(int is_pila, int index, t_pset *pset)
{
	t_link	**alk;
	int		data;

	alk = is_pila ? (&pset->pila): &(pset->pilb);
	cursor_by_index(alk, index);
	data = (*alk)->data;
	to_firstlk(alk);
	return (data);
}

int		index_first_inversion(t_link *alk)
{
	int count;

	count = 1;
	while (alk && alk->next)
	{
		if (alk->data < alk->next->data)
		{
			count++;
			alk = alk->next;
		}
		else
			return (count);
	}
	return (-1);
}
