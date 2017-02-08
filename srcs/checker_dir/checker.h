/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:41:25 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 16:37:26 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../includes/project.h"

typedef struct s_link	t_link;

void	print_data_prev(t_link *begin_pile);
void	print_data_next(t_link *begin_pile);
void	print_both(t_link **pile_a, t_link **pile_b);

int		ope_read(t_link **pile_a, t_link **pile_b, int option);
void	ch_ope_route(t_link **pile_a, t_link **pile_b, char *cmd);

#endif
