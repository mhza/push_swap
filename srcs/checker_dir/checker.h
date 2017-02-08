/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:41:25 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 14:29:43 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../includes/project.h"


typedef struct	s_link t_link;

// typedef struct	s_link
// {
// 	int				data;
// 	struct s_link	*next;
// 	struct s_link	*prev;
// }				t_link;

// int				init_pile(t_link **pile, int ac, char **av, int option);

void	free_link_ch(t_link **pile);

void			print_data_prev(t_link *begin_pile);
void			print_data_next(t_link *begin_pile);
void			print_both(t_link **pile_a, t_link **pile_b);

// t_link			*lknew(int data);
// void			lkadd(t_link **alk, t_link *new);
// void			to_firstlk(t_link **alk);
// void			to_lastlk(t_link **alk);
// int				countlk(t_link *alk);

int				is_twice(t_link *pile, int data);
int				is_sortlk(t_link *alk);
void			free_link(t_link **pile);
int				ret_err_free(t_link **pile_b, char *cmd);

int				ope_read(t_link **pile_a, t_link **pile_b, int option);
void			ch_ope_route(t_link **pile_a, t_link **pile_b, char *cmd);

// void			swap(t_link **top_pile);
// void			push(t_link **src, t_link **dest);
// void			rotate(t_link **top_pile);
// void			rrotate(t_link **bottom_pile);

#endif
