/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:52:12 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/26 21:29:31 by mhaziza          ###   ########.fr       */
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
	if (!src)
		ft_putstr("error : empty src\n");
	if (!(*dest))
	{	*dest = *src;
		*src = (*src)->next;
		(*dest)->next = NULL;}
	}
	else
	{

	}
}
// void	rotate(t_link **top_pile)
// {
//
// }
//
// void	rrotate(t_link **top_pile)
// {
//
// }
