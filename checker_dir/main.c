/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:21 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/05 23:44:59 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ret_main(t_link **pile, char *str, int ret, int print)
{
	if (!ft_strcmp(str, OK))
		ft_putstr(str);
	else
		write(2, str, ft_strlen(str));
	if (print)
	{
		to_firstlk(pile);
		print_data_next(*pile);
	}
// printf("adresse pile %p et *pile %p\n", pile, *pile);
	while (1)
		;
	return (ret);
}

int		main(int ac, char **av)
{
	int		count;
	int		option_print;
	int		option_pprint;
	t_link	*pile;
	t_link	*pile_b = NULL;

	if (ac == 1 || !av[1] || (av[1] && !ft_strcmp(av[1], EMPTS)))
		return (0);
	option_print = 0;
	option_pprint = 0;
	if (!ft_strcmp(av[1], OPTV) || !ft_strcmp(av[1], OPTP))
		option_print = 1;
	if (!ft_strcmp(av[1], OPTP))
		option_pprint = 1;
	if (!init_pile(&pile, ac, av, option_print))
		return (ret_main(&pile, ERROR, 0, 0));
	count = countlk(pile);
	if (ope_read(&pile, &pile_b, option_pprint) == READ_ERROR)
		return (ret_main(&pile, ERROR, 0, 0));
	if (count != countlk(pile) || !is_sortlk(pile))
		return (ret_main(&pile, KO, 0, option_print));
	else
		return (ret_main(&pile, OK, 1, option_print));


}
// echo "ra\nra\nra\nra\npb\npb\npb\npa\npb\n" | ./checker  -9 -8 2 0
