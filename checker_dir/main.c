/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:21 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 12:51:50 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ret_main_error(t_link **pila, t_link **pilb, char *str, int print)
{
	write(2, str, ft_strlen(str));
	if (print)
	{
		to_firstlk(pila);
		print_data_next(*pila);
		to_firstlk(pilb);
		print_data_next(*pilb);
	}
	to_firstlk(pila);
	to_firstlk(pilb);
	free_link(pila);
	free_link(pilb);
	return (0);
}

int		ret_main(t_link **pila, t_link **pilb, char *str, int print)
{
	ft_putstr(str);
	if (print)
	{
		to_firstlk(pila);
		print_data_next(*pila);
		to_firstlk(pilb);
		print_data_next(*pilb);
	}
	to_firstlk(pila);
	to_firstlk(pilb);
	free_link(pila);
	free_link(pilb);
	return (1);
}

int		main(int ac, char **av)
{
	int		count;
	int		option_print;
	int		option_pprint;
	t_link	*pile;
	t_link	*pile_b;

	if (ac == 1 || !av[1] || (av[1] && !ft_strcmp(av[1], EMPTS)))
		return (0);
	option_print = 0;
	option_pprint = 0;
	pile_b = NULL;
	if (!ft_strcmp(av[1], OPTV) || !ft_strcmp(av[1], OPTP))
		option_print = 1;
	if (!ft_strcmp(av[1], OPTP))
		option_pprint = 1;
	if (!init_pile(&pile, ac, av, option_print))
		return (ret_main(&pile, &pile_b, ERROR, option_print));
	count = countlk(pile);
	if (ope_read(&pile, &pile_b, option_pprint) == READ_ERROR)
		return (ret_main_error(&pile, &pile_b, ERROR, option_print));
	if (count != countlk(pile) || !is_sortlk(pile))
		return (ret_main_error(&pile, &pile_b, KO, option_print));
	else
		return (ret_main(&pile, &pile_b, OK, option_print));
}
