/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:22:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 15:52:13 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ch_ope_route(t_link **pile_a, t_link **pile_b, char *cmd)
{
	if (pile_a && (!ft_strcmp(cmd, SAL) || !ft_strcmp(cmd, SSL)))
		swap(pile_a);
	if (pile_b && (!ft_strcmp(cmd, SBL) || !ft_strcmp(cmd, SSL)))
		swap(pile_b);
	if (!ft_strcmp(cmd, PBL))
		push(pile_a, pile_b);
	if (!ft_strcmp(cmd, PAL))
		push(pile_b, pile_a);
	if (pile_a && (!ft_strcmp(cmd, RAL) || !ft_strcmp(cmd, RRL)))
		rotate(pile_a);
	if (pile_b && (!ft_strcmp(cmd, RBL) || !ft_strcmp(cmd, RRL)))
		rotate(pile_b);
	if (pile_a && (!ft_strcmp(cmd, RRAL) || !ft_strcmp(cmd, RRRL)))
		rrotate(pile_a);
	if (pile_b && (!ft_strcmp(cmd, RRBL) || !ft_strcmp(cmd, RRRL)))
		rrotate(pile_b);
}

int		ope_read(t_link **pile_a, t_link **pile_b, int option)
{
	char	*cmd;
	int		read;

	read = get_next_line(0, &cmd);
	while (read && read != READ_ERROR)
	{
		if (cmd && ft_strcmp(cmd, SAL) * ft_strcmp(cmd, SBL) * ft_strcmp(cmd, SSL)
			* ft_strcmp(cmd, PAL) * ft_strcmp(cmd, PBL)
			* ft_strcmp(cmd, RRAL) * ft_strcmp(cmd, RRBL) * ft_strcmp(cmd, RRRL)
			* ft_strcmp(cmd, RAL) * ft_strcmp(cmd, RBL) * ft_strcmp(cmd, RRL) == 0)
		{
			ch_ope_route(pile_a, pile_b, cmd);
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
