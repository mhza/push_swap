/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:35:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/02 17:37:16 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../libft/libft.h"

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

# define MININT -2147483648
# define MAXINT 2147483647

typedef struct	s_link
{
	int				data;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

typedef struct	s_pset
{
	t_link			*pila;
	t_link			*pilb;
	int				siza;
	int				sizb;
	char			*opes;
}				t_pset;

t_link			*set_pile(char *str);
int				init_pile(t_link **pile, int ac, char **av, int option);

void			print_data_prev(t_link *begin_pile);
void			print_data_next(t_link *begin_pile);
void			print_both(t_link **pile_a, t_link **pile_b);
int				ret_main(t_link **pile, char *str, int ret, int print);

t_link			*lknew(int data);
void			lkadd(t_link **alk, t_link *new);
void			to_firstlk(t_link **alk);
void			to_lastlk(t_link **alk);
int				countlk(t_link *alk);

int				is_twice(t_link *pile, int data);
int				is_twice_global(t_link *hash_pile, t_link *pile);
int				is_sortlk(t_link *alk);
void			free_link(t_link **pile);
int				ret_err_free(t_link **pile_b, char *cmd);

void			cursor_by_data(t_link **alk, int data);
void			cursor_by_index(t_link **alk, int index);
int				get_minlk(int is_pila, t_pset *pset);
int				index_first_inversion(t_link *alk);
int				get_index(int is_pila, int data, t_pset *pset);
int				get_data(int is_pila, int index, t_pset *pset);

char			*ft_strreald(char *s1, char *s2);
char			*ft_strreal(char *s1, char *s2);

void			mv_top(int is_pila, int index, t_pset *pset);
void			add_one_ope(char *ope, t_pset *pset);
void			ope_route(t_pset *pset, char *cmd);

void			simplest_case(int is_pila, t_pset *pset);

#endif
