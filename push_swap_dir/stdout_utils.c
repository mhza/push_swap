/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:19:20 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/04 19:58:54 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_data_prev(t_link *begin_pile)
{
	while (begin_pile)
	{
		ft_putnbr(begin_pile->data);
		ft_putstr(" ");
		begin_pile = begin_pile->prev;
	}
	ft_putstr("\n");
}

void	print_data_next(t_link *begin_pile)
{
	while (begin_pile)
	{
		ft_putnbr(begin_pile->data);
		ft_putstr(" ");
		begin_pile = begin_pile->next;
	}
	ft_putstr("\n");
}

void	print_both(t_link **pile_a, t_link **pile_b)
{
	ft_putstr("A > ");
	if (pile_a)
		print_data_next(*pile_a);
	else
		ft_putstr("(null)\n");
	ft_putstr("B > ");
	if (pile_b)
		print_data_next(*pile_b);
	else
		ft_putstr("(null)\n");
	ft_putstr("\n");
}

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
	 printf("ret_main    %p  \n", str);

	return (ret);
}
