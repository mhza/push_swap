/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:52:12 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/27 15:16:26 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_link **top_pile)
{
	int	tmp;

	if ((*top_pile) && (*top_pile)->next)
	{
		tmp = (*top_pile)->data;
		(*top_pile)->data = (*top_pile)->next->data;
		(*top_pile)->next->data = tmp;
	}
}

void	push(t_link **src, t_link **dest)
{
	if (!(*src))
		ft_putstr("error : empty src\n");
	else if (!(*dest))
	{
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = NULL;
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
void	rotate(t_link **top_pile)
{
		int	tmp;

		if (*top_pile)
			tmp = (*top_pile)->data;
		while (*top_pile && (*top_pile)->next)
		{
			(*top_pile)->data = (*top_pile)->next->data;
			(*top_pile) = (*top_pile)->next;
		}
		if (*top_pile)
			(*top_pile)->data = tmp;
		to_firstlk(top_pile);
}

void	rrotate(t_link **bottom_pile)
{
	int	tmp;

	to_lastlk(bottom_pile);
	if (*bottom_pile)
		tmp = (*bottom_pile)->data;
	while ((*bottom_pile) && (*bottom_pile)->prev)
	{
		(*bottom_pile)->data = (*bottom_pile)->prev->data;
		(*bottom_pile) = (*bottom_pile)->prev;
	}
	if (*bottom_pile)
		(*bottom_pile)->data = tmp;
	to_firstlk(bottom_pile);
}
