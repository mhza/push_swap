/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:41:08 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 13:48:16 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_link	*lknew(int data)
{
	t_link	*new;

	if ((new = ft_memalloc(sizeof(t_link))) == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lkadd(t_link **alk, t_link *new)
{
	new->prev = *alk;
	*alk = new;
}

void	to_firstlk(t_link **alk)
{
	while ((*alk) && (*alk)->prev)
		(*alk) = (*alk)->prev;
}

void	to_lastlk(t_link **alk)
{
	while ((*alk) && (*alk)->next)
		(*alk) = (*alk)->next;
}

int		countlk(t_link *alk)
{
	int	i;

	i = 0;
	while (alk)
	{
		i++;
		alk = alk->next;
	}
	return (i);
}
