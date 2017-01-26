/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:41:08 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/25 23:20:00 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_link	*lknew(int data, int index)
{
	t_link	*new;
	if ((new = ft_memalloc(sizeof(t_link))) == NULL)
		return (NULL);
	new->index = index;
	new->data = data;
	new->is_first = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lkadd(t_link **alk, t_link *new)
{
	new->prev = *alk;
	*alk = new;
}

t_link	*set_pile(char *str)
{
	int		i = 0;
	int		count = 1;
	t_link	*new;
	t_link	*pile;

	while (str && str[i] && str[i] == ' ')
		i++;
	if ((pile = lknew(ft_atoi(str + i), count)) == NULL)
		return (NULL);
	count++;
	while (str && str[i] && str[i] != ' ')
		i++;
	while (str && str[i])
	 {
		while (str && str[i] && str[i] == ' ')
			i++;
		if (str[i] && ft_isdigit(str[i]))
		{
			new = lknew(ft_atoi(str + i), count);
			lkadd(&pile, new);
			new->prev->next = new;
			count++;
		}
		while (str && str[i] && str[i] != ' ')
			i++;
	}
	return (pile);
}
