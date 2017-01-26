/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zar_functor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:52:12 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/26 18:46:34 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_link **top_pile)
{
	t_link	*tmp;

	tmp = lknew((*top_pile)->next->data, (*top_pile)->next->index);
	if ((*top_pile) && (*top_pile)->next && (*top_pile)->next->next)
		(*top_pile)->next->next->prev = (*top_pile);
	if ((*top_pile) && (*top_pile)->next)
		(*top_pile)->next = (*top_pile)->next->next;
	tmp->next = (*top_pile);
	*top_pile = tmp;
}
