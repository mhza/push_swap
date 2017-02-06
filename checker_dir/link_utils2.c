/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:49:35 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 12:49:37 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_sortlk(t_link *alk)
{
	while (alk && alk->next)
	{
		if (alk->data > alk->next->data)
			return (0);
		alk = alk->next;
	}
	return (1);
}

void	free_link(t_link **pile)
{
	if (pile)
	{
		to_firstlk(pile);
		while (*pile && (*pile)->next)
		{
			*pile = (*pile)->next;
			free((*pile)->prev);
		}
		if (*pile)
			free(*pile);
	}
}

int		ret_err_free(t_link **pile_b, char *cmd)
{
	if (cmd)
		free(cmd);
	free_link(pile_b);
	return (READ_ERROR);
}

int		is_twice(t_link *pile, int data)
{
	t_link	*tmp;

	tmp = pile;
	to_firstlk(&pile);
	while (pile)
	{
		if (data == pile->data)
		{
			to_firstlk(&pile);
			free_link(&pile);
			return (0);
		}
		pile = pile->next;
	}
	pile = tmp;
	return (1);
}
