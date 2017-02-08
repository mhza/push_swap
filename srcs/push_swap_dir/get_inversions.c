/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:17:16 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 15:42:06 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		index_first_inversion(int is_pila, t_pset *pset)
{
	int		count;
	t_link	*alk;

	count = 1;
	if (!pset)
		return (-1);
	alk = is_pila ? pset->pila : pset->pilb;
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

int		index_first_inversion_dec(int is_pila, t_pset *pset)
{
	int		count;
	t_link	*alk;

	count = 1;
	alk = is_pila ? pset->pila : pset->pilb;
	while (alk && alk->next)
	{
		if (alk->data > alk->next->data)
		{
			count++;
			alk = alk->next;
		}
		else
			return (count);
	}
	return (-1);
}
