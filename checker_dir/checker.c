/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:22:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/06 12:50:22 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ope_route(t_link **pile_a, t_link **pile_b, char *cmd)
{
	if (pile_a && (!ft_strcmp(cmd, SA) || !ft_strcmp(cmd, SS)))
		swap(pile_a);
	if (pile_b && (!ft_strcmp(cmd, SB) || !ft_strcmp(cmd, SS)))
		swap(pile_b);
	if (!ft_strcmp(cmd, PB))
		push(pile_a, pile_b);
	if (!ft_strcmp(cmd, PA))
		push(pile_b, pile_a);
	if (pile_a && (!ft_strcmp(cmd, RA) || !ft_strcmp(cmd, RR)))
		rotate(pile_a);
	if (pile_b && (!ft_strcmp(cmd, RB) || !ft_strcmp(cmd, RR)))
		rotate(pile_b);
	if (pile_a && (!ft_strcmp(cmd, RRA) || !ft_strcmp(cmd, RRR)))
		rrotate(pile_a);
	if (pile_b && (!ft_strcmp(cmd, RRB) || !ft_strcmp(cmd, RRR)))
		rrotate(pile_b);
}

int		ope_read(t_link **pile_a, t_link **pile_b, int option)
{
	char	*cmd;
	int		read;

	read = get_next_line(0, &cmd);
	while (read && read != READ_ERROR)
	{
		if (cmd && ft_strcmp(cmd, SA) * ft_strcmp(cmd, SB) * ft_strcmp(cmd, SS)
			* ft_strcmp(cmd, PA) * ft_strcmp(cmd, PB)
			* ft_strcmp(cmd, RRA) * ft_strcmp(cmd, RRB) * ft_strcmp(cmd, RRR)
			* ft_strcmp(cmd, RA) * ft_strcmp(cmd, RB) * ft_strcmp(cmd, RR) == 0)
		{
			ope_route(pile_a, pile_b, cmd);
			if (option)
				print_both(pile_a, pile_b);
		}
		else if (ft_strcmp(cmd, "") || get_next_line(0, &cmd))
		{
			free(cmd);
			return (-1);
		}
		if (cmd)
			free(cmd);
		read = get_next_line(0, &cmd);
	}
	return (READ_END);
}
