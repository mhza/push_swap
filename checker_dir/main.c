/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:21 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/01 18:52:46 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (!ft_strcmp(av[1], "-p") || !ft_strcmp(av[1], "-v"))
		option_print = 1;
	if (!ft_strcmp(av[1], "-v"))
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
