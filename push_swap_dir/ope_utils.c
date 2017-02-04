/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:52:12 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/04 21:14:59 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_link **top_pile)
{
	int	tmp;
	int	tmp_pack;

	if ((*top_pile) && (*top_pile)->next)
	{
		tmp = (*top_pile)->data;
		tmp_pack = (*top_pile)->pack;
		(*top_pile)->data = (*top_pile)->next->data;
		(*top_pile)->next->data = tmp;
		(*top_pile)->pack = (*top_pile)->next->pack;
		(*top_pile)->next->pack = tmp_pack;
	}
}

void	push(t_link **src, t_link **dest)
{
	if ((*src))
	{
		if (!(*dest))
		{
			*dest = *src;
			*src = (*src)->next;
			(*dest)->next = NULL;
			(*src)->prev = NULL;
		}
		else if ((*src)->next)
		{
			(*dest)->prev = *src;
			(*src) = (*src)->next;
			(*dest)->prev->next = *dest;
			*dest = (*dest)->prev;
			(*src)->prev = NULL;
		}
		else
		{
			(*dest)->prev = *src;
			(*src)->next = *dest;
			*dest = (*dest)->prev;
			*src = NULL;
		}
	}
}

void	rotate(t_link **top_pile)
{
	int	tmp;
	int	tmp_pack;

	if (*top_pile && (*top_pile)->next)
	{
		tmp = (*top_pile)->data;
		tmp_pack = (*top_pile)->pack;
		while ((*top_pile)->next)
		{
			(*top_pile)->data = (*top_pile)->next->data;
			(*top_pile)->pack = (*top_pile)->next->pack;
			(*top_pile) = (*top_pile)->next;
		}
		(*top_pile)->data = tmp;
		(*top_pile)->pack = tmp_pack;
		to_firstlk(top_pile);
	}
}

void	rrotate(t_link **bottom_pile)
{
	int	tmp;
	int	tmp_pack;

	if (*bottom_pile && (*bottom_pile)->next)
	{
		to_lastlk(bottom_pile);
		tmp = (*bottom_pile)->data;
		tmp_pack = (*bottom_pile)->pack;
		while ((*bottom_pile) && (*bottom_pile)->prev)
		{
			(*bottom_pile)->data = (*bottom_pile)->prev->data;
			(*bottom_pile)->pack = (*bottom_pile)->prev->pack;
			(*bottom_pile) = (*bottom_pile)->prev;
		}
		(*bottom_pile)->data = tmp;
		(*bottom_pile)->pack = tmp_pack;
		to_firstlk(bottom_pile);
	}
}

void	ope_route(t_pset *pset, char *cmd)
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
