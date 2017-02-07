/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainedlk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:24:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 15:02:04 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// int		get_last(int is_pila, t_pset *pset)
// {
// 	int		data;
// 	t_link	*alk;
//
// 	alk = is_pila ? pset->pila : pset->pilb;
// 	to_lastlk(&alk);
// 	data = alk->data;
// 	to_firstlk(&alk);
// 	return (data);
// }
//
// int		get_first(int is_pila, t_pset *pset)
// {
// 	int		data;
// 	t_link	*alk;
//
// 	alk = is_pila ? pset->pila : pset->pilb;
// 	to_firstlk(&alk);
// 	data = alk->data;
// 	return (data);
// }
