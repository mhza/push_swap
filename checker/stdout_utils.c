/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:19:20 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/28 18:20:15 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
