/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:21 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/28 15:36:19 by mhaziza          ###   ########.fr       */
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

t_link	*set_pile(char *str)
{
	int		i;
	t_link	*new;
	t_link	*pile;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str && str[i] && !ft_isdigit(str[i]) && str[i] != ' ')
		return (NULL);
	if ((pile = lknew(ft_atoi(str + i))) == NULL)
		return (NULL);
	while (str && str[i] && str[i] != ' ' && ft_isdigit(str[i]))
		i++;
	while (str && str[i])
	{
		while (str && str[i] && str[i] == ' ')
			i++;
		if (str && str[i] && !ft_isdigit(str[i]) && str[i] != ' ')
			return (NULL);
		if (str[i] && ft_isdigit(str[i]))
		{
			new = lknew(ft_atoi(str + i));
			lkadd(&pile, new);
			new->prev->next = new;
		}
		while (str && str[i] && str[i] != ' ' && ft_isdigit(str[i]))
			i++;
	}
	return (pile);
}

int		main(int ac, char **av)
{
	int		i;
	int		count;
	t_link	*pile;
	t_link	*hash_pile;

	if (ac == 1 || !av[1])
		return (0);
	if ((pile = set_pile(av[1])) == NULL)
	{
		free_link(&pile);
		ft_putstr("Error\n");
		return (-1);
	}
	i = 1;
	while (++i < ac && av[i])
	{
		if ((hash_pile = set_pile(av[i])) == NULL)
		{
			free_link(&pile);
			free_link(&hash_pile);
			ft_putstr("Error\n");
			return (-1);
		}
		to_firstlk(&hash_pile);
		pile->next = hash_pile;
		hash_pile->prev = pile;
		to_lastlk(&pile);
	}
	to_firstlk(&pile);
	count = countlk(pile);
	print_data_next(pile);
	ft_putstr("==============\n");
	if (ope_read(&pile) == READ_ERROR)
	{
		free_link(&pile);
		ft_putstr("Error\n");
		return (-1);
	}
	if (count != countlk(pile) || !is_sortlk(pile))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	print_data_next(pile);
	free_link(&pile);
	return (1);
}
