/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:41:25 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/25 23:25:21 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
#include "../libft/libft.h"

typedef struct	s_link
{
	int				data;
	int				index;
	int				is_first;
	struct	s_link	*next;
	struct	s_link	*prev;
}				t_link;

void	print_data_prev(t_link *begin_pile);
void	print_data_next(t_link *begin_pile);

t_link	*set_pile(char *str);
#endif
