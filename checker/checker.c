/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:22:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/27 16:06:31 by mhaziza          ###   ########.fr       */
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

int		ope_read(t_link **pile_a)
{
	char	*cmd;
	int		read;
	t_link	**pile_b;

	pile_b = ft_memalloc(sizeof(t_link*));
	*pile_b = NULL;
	read = get_next_line(0, &cmd);
	while (read && read != READ_ERROR)
	{
		if (cmd && ft_strcmp(cmd, SA)*ft_strcmp(cmd, SB)*ft_strcmp(cmd, SS)
				*ft_strcmp(cmd, PA)*ft_strcmp(cmd, PB)
				*ft_strcmp(cmd, RA)*ft_strcmp(cmd, RB)*ft_strcmp(cmd, RR)
				*ft_strcmp(cmd, RRA)*ft_strcmp(cmd, RRB)*ft_strcmp(cmd, RRR) == 0)
			ope_route(pile_a, pile_b, cmd);
		else
		{
			ft_putstr("Error");
			return (READ_ERROR);
		}
		ft_putstr("A > ");
		if (pile_a)
			print_data_next(*pile_a);
		ft_putstr("B > ");
		if (pile_b)
			print_data_next(*pile_b);
		else
			ft_putstr("(null)\n");
		ft_putstr("\n");
		read = get_next_line(0, &cmd);
	}
	return (READ_ERROR);
}
