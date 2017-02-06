/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainedlk_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:16:14 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 22:38:40 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cursor_by_data(t_link **alk, int data)
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

// int		get_pindex(t_link	*alk)
// {
// 	int		count;
//
// 	count = 1;
// 	while (alk && alk->data != data)
// 	{
// 		count++;
// 		alk = alk->next;
// 	}
// 	return (count);
// }

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

	alk = is_pila ? (&pset->pila) : &(pset->pilb);
	cursor_by_index(alk, index);
	data = (*alk)->data;
	to_firstlk(alk);
	return (data);
}
