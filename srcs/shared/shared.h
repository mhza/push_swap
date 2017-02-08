/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:41:25 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 15:49:02 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include "../../includes/project.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

# define SAL "sa"
# define SBL "sb"
# define SSL "ss"
# define PAL "pa"
# define PBL "pb"
# define RAL "ra"
# define RBL "rb"
# define RRL "rr"
# define RRAL "rra"
# define RRBL "rrb"
# define RRRL "rrr"

# define OPTV "-v"
# define OPTP "-p"
# define EMPTS ""
# define ERROR "Error\n"
# define KO "KO\n"
# define OK "OK\n"
# define MININT -2147483648
# define MAXINT 2147483647

typedef struct	s_link
{
	int				data;
	int				pack;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

int				init_pile(t_link **pile, int ac, char **av, int option);

t_link			*lknew(int data);
void			lkadd(t_link **alk, t_link *new);
void			to_firstlk(t_link **alk);
void			to_lastlk(t_link **alk);
int				countlk(t_link *alk);

void			swap(t_link **top_pile);
void			push(t_link **src, t_link **dest);
void			rotate(t_link **top_pile);
void			rrotate(t_link **bottom_pile);

#endif
