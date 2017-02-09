/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:22:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/09 14:38:17 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ch_ope_route(t_link **pile_a, t_link **pile_b, char *ln)
{
	if (pile_a && (!ft_strcmp(ln, SAL) || !ft_strcmp(ln, SSL)))
		swap(pile_a);
	if (pile_b && (!ft_strcmp(ln, SBL) || !ft_strcmp(ln, SSL)))
		swap(pile_b);
	if (!ft_strcmp(ln, PBL))
		push(pile_a, pile_b);
	if (!ft_strcmp(ln, PAL))
		push(pile_b, pile_a);
	if (pile_a && (!ft_strcmp(ln, RAL) || !ft_strcmp(ln, RRL)))
		rotate(pile_a);
	if (pile_b && (!ft_strcmp(ln, RBL) || !ft_strcmp(ln, RRL)))
		rotate(pile_b);
	if (pile_a && (!ft_strcmp(ln, RRAL) || !ft_strcmp(ln, RRRL)))
		rrotate(pile_a);
	if (pile_b && (!ft_strcmp(ln, RRBL) || !ft_strcmp(ln, RRRL)))
		rrotate(pile_b);
}

int		ope_read(t_link **pile_a, t_link **pile_b, int option)
{
	char	*ln;
	int		read;

	while ((read = get_next_line(0, &ln)) && read != READ_ERROR)
	{
		if (ln && ft_strcmp(ln, SAL) * ft_strcmp(ln, SBL) * ft_strcmp(ln, SSL)
			* ft_strcmp(ln, PAL) * ft_strcmp(ln, PBL) * ft_strcmp(ln, RRAL)
			* ft_strcmp(ln, RRBL) * ft_strcmp(ln, RRRL) * ft_strcmp(ln, RAL)
			* ft_strcmp(ln, RBL) * ft_strcmp(ln, RRL) == 0)
		{
			ch_ope_route(pile_a, pile_b, ln);
			if (option)
				print_both(pile_a, pile_b);
			free(ln);
		}
		else
		{
			free(ln);
			return (-1);
		}
	}
	return (READ_END);
}
