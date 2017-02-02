/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:52:34 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/01 18:52:43 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*set_pile_init(char *str, t_link **pile)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str && str[i] && !ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
		return (NULL);
	if (str && str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
	{
		if ((str[i] == '-' && str[i + 1] && !ft_isdigit(str[i + 1])) ||
		ft_atoli(str + i) < MININT || ft_atoli(str + i) > MAXINT)
			return (NULL);
		if ((*pile = lknew(ft_atoli(str + i))) == NULL)
			return (NULL);
		i = ft_atoli(str + i) < 0 ? i + 1 : i;
	}
	while (str && str[i] && str[i] != ' ' && ft_isdigit(str[i]))
		i++;
	return (str + i);
}

int		hooklk(t_link **pile, char *str, int i)
{
	t_link	*new;

	if (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
	{
		if (ft_atoli(str + i) < MININT || ft_atoli(str + i) > MAXINT)
			return (-1);
		new = lknew(ft_atoli(str + i));
		i = ft_atoli(str + i) < 0 ? i + 1 : i;
		if (!is_twice(*pile, new->data))
			return (-1);
		lkadd(pile, new);
		new->prev->next = new;
	}
	return (i);
}

t_link	*set_pile(char *str)
{
	int		i;
	t_link	*pile;

	if ((str = set_pile_init(str, &pile)) == NULL)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && !ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (NULL);
		if (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
		{
			if ((str[i] == '-' && str[i + 1] && !ft_isdigit(str[i + 1])))
				return (NULL);
			else
				hooklk(&pile, str, i);
		}
		while (str[i] && str[i] != ' ' && ft_isdigit(str[i]))
			i++;
	}
	return (pile);
}

int		init_pile(t_link **pile, int ac, char **av, int option)
{
	int		i;
	t_link	*hash_pile;

	i = 1 + option;
	if ((*pile = set_pile(av[i])) == NULL)
		return (0);
	while (++i < ac && av[i])
	{
		if (ft_strlen(av[i]) == 1 && !ft_isdigit(av[i][0]))
			return (0);
		if ((hash_pile = set_pile(av[i])) == NULL ||
		!is_twice_global(hash_pile, *pile))
			return (0);
		to_firstlk(&hash_pile);
		(*pile)->next = hash_pile;
		hash_pile->prev = *pile;
		to_lastlk(pile);
	}
	to_firstlk(pile);
	return (1);
}
