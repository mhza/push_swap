/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_getstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:59:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 15:48:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*ft_strreal(char *s1, char *s2)
{
	char	*new;

	new = NULL;
	if (s1 == NULL || *s1 == '\0')
		new = ft_strdup(s2);
	else if ((new = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	free(s1);
	return (new);
}

void	mv_top(int is_pila, int index, t_pset *pset)
{
	int		size;
	int		i;
	char	*ope;

	if (!pset || index < 0)
		return ;
	size = is_pila ? countlk(pset->pila) : countlk(pset->pilb);
	i = -1;
	if (pset && index > size / 2 + 1)
	{
		ope = is_pila ? RRA : RRB;
		while (++i < size - index + 1)
			add_one_ope(ope, pset);
	}
	else
	{
		ope = is_pila ? RA : RB;
		while (++i < index - 1)
			add_one_ope(ope, pset);
	}
}

void	add_one_ope(char *ope, t_pset *pset)
{
	pset->opes = ft_strreal(pset->opes, ope);
	ope_route(pset, ope);
}
