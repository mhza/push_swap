/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:21 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/28 18:44:21 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ret_main(t_link **pile, char *str, int ret, int print)
{
	if (!ft_strcmp(str, "OK\n"))
		ft_putstr(str);
	else
		write(2, str, ft_strlen(str));
	if (print)
	{
		to_firstlk(pile);
		print_data_next(*pile);
	}
	free_link(pile);
	return (ret);
}

char	*set_pile_init(char *str, t_link **pile)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str && str[i] && !ft_isdigit(str[i]) && str[i] != ' ')
		return (NULL);
	if ((*pile = lknew(ft_atoi(str + i))) == NULL)
		return (NULL);
	while (str && str[i] && str[i] != ' ' && ft_isdigit(str[i]))
		i++;
	return (str + i);
}

t_link	*set_pile(char *str)
{
	int		i;
	t_link	*new;
	t_link	*pile;

	if ((str = set_pile_init(str, &pile)) == NULL)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		while (str && str[i] && str[i] == ' ')
			i++;
		if (str && str[i] && !ft_isdigit(str[i]) && str[i] != ' ')
			return (NULL);
		if (str[i] && ft_isdigit(str[i]))
		{
			new = lknew(ft_atoi(str + i));
			if (!is_twice(pile, new->data))
				return (NULL);
			lkadd(&pile, new);
			new->prev->next = new;
		}
		while (str && str[i] && str[i] != ' ' && ft_isdigit(str[i]))
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

int		main(int ac, char **av)
{
	int		count;
	int		option_print;
	int		option_pprint;
	t_link	*pile;

	if (ac == 1 || !av[1] || (av[1] && !ft_strcmp(av[1], "")))
		return (0);
	option_print = 0;
	option_pprint = 0;
	if (!ft_strcmp(av[1], "-p") || !ft_strcmp(av[1], "-pp"))
		option_print = 1;
	if (!ft_strcmp(av[1], "-pp"))
		option_pprint = 1;
	if (!init_pile(&pile, ac, av, option_print))
		return (ret_main(&pile, "Error\n", 0, 0));
	count = countlk(pile);
	if (ope_read(&pile, option_pprint) == READ_ERROR)
		return (ret_main(&pile, "Error\n", 0, 0));
	if (count != countlk(pile) || !is_sortlk(pile))
		return (ret_main(&pile, "KO\n", 0, option_print));
	else
		return (ret_main(&pile, "OK\n", 1, option_print));
}
