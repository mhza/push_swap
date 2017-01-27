/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:21 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/27 16:09:49 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


t_link	*set_pile(char *str)
{
	int		i = 0;
	t_link	*new;
	t_link	*pile;

	while (str && str[i] && str[i] == ' ')
		i++;
	if ((pile = lknew(ft_atoi(str + i))) == NULL)
		return (NULL);
	while (str && str[i] && str[i] != ' ')
		i++;
	while (str && str[i])
	 {
		while (str && str[i] && str[i] == ' ')
			i++;
		if (str[i] && ft_isdigit(str[i]))
		{
			new = lknew(ft_atoi(str + i));
			lkadd(&pile, new);
			new->prev->next = new;
		}
		while (str && str[i] && str[i] != ' ')
			i++;
	}
	return (pile);
}

int main(int ac, char **av)
{
	int		i;
	t_link	*pile;
	t_link	*hash_pile;

	if (ac == 1 || !av[1])
		return (0);
	if ((pile = set_pile(av[1])) == NULL)
		return (-1);
	i = 1;
	while (++i < ac && av[i])
	{
		if ((hash_pile = set_pile(av[i])) == NULL)
			return (-1);
		to_firstlk(&hash_pile);
		pile->next = hash_pile;
		hash_pile->prev = pile;
		to_lastlk(&pile);
	}
	to_firstlk(&pile);
	print_data_next(pile);
	ft_putstr("==============\n");
	ope_read(&pile);

	return (1);
}
