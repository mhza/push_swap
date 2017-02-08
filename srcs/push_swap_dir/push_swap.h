/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:35:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/08 18:05:42 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../includes/project.h"

typedef struct s_link	t_link;
typedef struct	s_pset
{
	t_link			*pila;
	t_link			*pilb;
	int				siza;
	int				sizb;
	int				mina;
	int				minb;
	int				maxa;
	int				maxb;
	char			*opes;
}				t_pset;

typedef struct	s_count
{
	int		mid_val;
	int		count;
	int		sz;
	int		sz_tmp;
	int		sz_cpy;
}				t_count;

int				get_index(int is_pila, int data, t_pset *pset);
void			cursor_by_index(t_link **alk, int index);
int				get_min(int is_pila, t_pset *pset);
int				get_min2(int is_pila, t_pset *pset);
int				get_max(int is_pila, t_pset *pset);

int				index_first_inversion(int is_pila, t_pset *pset);
int				index_first_inversion_dec(int is_pila, t_pset *pset);

char			*ft_strreal(char *s1, char *s2);
void			mv_top(int is_pila, int index, t_pset *pset);
void			add_one_ope(char *ope, t_pset *pset);
void			ope_route(t_pset *pset, char *cmd);

int				find_mid_pile(t_link *pile, int size, int min, int max);
int				find_mid_pile2(t_link *pile, int size, int min, int max);
int				find_midd(int is_pila, t_pset *pset);
int				get_max_six_times_two(int is_pila, t_pset *pset);

void			split_pile(int is_pila, t_pset *pset);

int				get_min_max_mid(int is_pila, t_pset *pset);
int				get_set_pack_size(int is_pila, t_pset *pset);

t_pset			*split_pack(int is_pila, t_pset *pset);

void			three_left_sort(int is_pila, t_pset *pset, int nsort);
void			three_left_nsort(int is_pila, t_pset *pset);
void			under_five(int is_pila, t_pset *pset);
void			short_cut(int is_pila, t_pset *pset);

#endif
