/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:22:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/28 15:37:15 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_link(t_link **pile)
{
	if (pile)
	{
		while (*pile && (*pile)->next)
		{
			*pile = (*pile)->next;
			free((*pile)->prev);
		}
		free(*pile);
	}
}

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
	free(cmd);
// ft_putstr("A > ");
// if (pile_a)
// 	print_data_next(*pile_a);
// ft_putstr("B > ");
// if (pile_b)
// 	print_data_next(*pile_b);
// else
// 	ft_putstr("(null)\n");
// ft_putstr("\n");
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
		if (cmd && ft_strcmp(cmd, SA) * ft_strcmp(cmd, SB) * ft_strcmp(cmd, SS)
			* ft_strcmp(cmd, PA) * ft_strcmp(cmd, PB)
			* ft_strcmp(cmd, RRA) * ft_strcmp(cmd, RRB) * ft_strcmp(cmd, RRR)
			* ft_strcmp(cmd, RA) * ft_strcmp(cmd, RB) * ft_strcmp(cmd, RR) == 0)
			ope_route(pile_a, pile_b, cmd);
		else if (!ft_strcmp(cmd, "") && get_next_line(0, &cmd))
		{
			free(cmd);
			free_link(pile_b);
			return (READ_ERROR);
		}
		else if (ft_strcmp(cmd, ""))
		{
			free(cmd);
			free_link(pile_b);
			return (READ_ERROR);
		}
		read = get_next_line(0, &cmd);
	}

	return (READ_END);
}

// int		ope_read(t_link **pile_a)
// {
// 	char	*cmd;
// 	int		read;
// 	t_link	**pile_b;
// 	int		fd;
// 	char	buffer[BUFF_SIZE];
//
// 	fd = open("to_check", O_WRONLY | O_CREAT | O_APPEND);
// 	read = 1;
// 	while ((read = read(0, buffer, BUFF_SIZE)))
// 		ft_putstr_fd(buffer, fd);
// 	pile_b = ft_memalloc(sizeof(t_link*));
// 	*pile_b = NULL;
// 	read = get_next_line(fd, &cmd);
// 	while (read && read != READ_ERROR)
// 	{
// 		if (cmd && ft_strcmp(cmd, SA)*ft_strcmp(cmd, SB)*ft_strcmp(cmd, SS)
// 				*ft_strcmp(cmd, PA)*ft_strcmp(cmd, PB)
// 				*ft_strcmp(cmd, RRA)*ft_strcmp(cmd, RRB)*ft_strcmp(cmd, RRR)
// 				*ft_strcmp(cmd, RA)*ft_strcmp(cmd, RB)*ft_strcmp(cmd, RR) == 0)
// 			ope_route(pile_a, pile_b, cmd);
// 		else if (!ft_strcmp(cmd, "") && get_next_line(fd, &cmd))
// 			return (READ_ERROR);
// 		read = get_next_line(fd, &cmd);
// 	}
// 	close(fd);
// 	return (READ_END);
// }
