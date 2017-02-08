/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:52:34 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 13:48:28 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int			is_twice(t_link *pile, int data)
{
	to_firstlk(&pile);
	while (pile)
	{
		if (data == pile->data)
			return (0);
		pile = pile->next;
	}
	return (1);
}

static char	*set_pile_init(char *str, t_link **pile)
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

static int	hooklk(t_link **pile, char *str, int i)
{
	t_link	*new;

	if (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
	{
		if (ft_atoli(str + i) < MININT || ft_atoli(str + i) > MAXINT)
			return (-1);
		new = lknew(ft_atoli(str + i));
		i = ft_atoli(str + i) < 0 ? i + 1 : i;
		if (!is_twice(*pile, new->data))
		{
			free(new);
			return (-1);
		}
		lkadd(pile, new);
		new->prev->next = new;
	}
	return (i);
}

static int	set_pile(t_link **pile, char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && !ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		if (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
		{
			if ((str[i] == '-' && str[i + 1] && !ft_isdigit(str[i + 1])))
				return (0);
			else if (*pile)
				if (hooklk(pile, str, i) == -1)
					return (0);
		}
		i = (*pile)->data < 0 ? i + 1 : i;
		while (str[i] && str[i] != ' ' && ft_isdigit(str[i]))
			i++;
	}
	return (1);
}

int			init_pile(t_link **pile, int ac, char **av, int option)
{
	int		i;

	i = 1 + option;
	if ((av[i] = set_pile_init(av[i], pile)) == NULL)
		return (0);
	while (i < ac && av[i])
	{
		to_lastlk(pile);
		if (ft_strlen(av[i]) == 1 && !ft_isdigit(av[i][0]))
			return (0);
		if (!set_pile(pile, av[i]))
			return (0);
		i++;
	}
	to_firstlk(pile);
	return (1);
}
