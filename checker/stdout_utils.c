/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:19:20 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/26 19:38:13 by mhaziza          ###   ########.fr       */
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
