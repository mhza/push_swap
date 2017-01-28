/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zar_functor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:52:12 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/28 15:39:19 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_link **top_pile)
{
	t_link	*tmp;

	tmp = lknew((*top_pile)->next->data, (*top_pile)->next->index);
	if ((*top_pile) && (*top_pile)->next && (*top_pile)->next->next)
		(*top_pile)->next->next->prev = (*top_pile);
	if ((*top_pile) && (*top_pile)->next)
		(*top_pile)->next = (*top_pile)->next->next;
	tmp->next = (*top_pile);
	*top_pile = tmp;
}




// ft_putstr("A > ");
// if (pile_a)
// 	print_data_next(*pile_a);
// ft_putstr("B > ");
// if (pile_b)
// 	print_data_next(*pile_b);
// else
// 	ft_putstr("(null)\n");
// ft_putstr("\n");


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
