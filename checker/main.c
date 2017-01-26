/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:21 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/25 23:16:52 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int ac, char **av)
{
	int		i;
	t_link	*pile;
	t_link	*hash_pile;

	if (ac == 1 || !av[1])
		return (0);
	if ((hash_pile = set_pile(av[1])) == NULL)
		return (-1);
	pile = hash_pile;
	i = 2;
	while (i < ac && av[i])
	{
		if ((hash_pile = set_pile(av[i])) == NULL)
			return (-1);
		while (hash_pile && hash_pile->prev)
			hash_pile = hash_pile->prev;
		pile->next = hash_pile;
		hash_pile->prev = pile;
		while (pile && pile->next)
			pile = pile->next;
		i++;
	}
	print_data_prev(pile);
	return (1);
}
