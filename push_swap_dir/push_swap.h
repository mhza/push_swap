/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:35:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/07 14:41:53 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

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
	int				pack;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

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

int				get_min(int is_pila, t_pset *pset);
int				get_min2(int is_pila, t_pset *pset);
int				get_max(int is_pila, t_pset *pset);
int				get_last(int is_pila, t_pset *pset);
int				get_first(int is_pila, t_pset *pset);

int				index_first_inversion(int is_pila, t_pset *pset);
int				index_first_inversion_dec(int is_pila, t_pset *pset);
int				index_last_inversion(int is_pila, t_pset *pset);

int				get_index(int is_pila, int data, t_pset *pset);
int				get_data(int is_pila, int index, t_pset *pset);
void			cursor_by_data(t_link **alk, int data);
void			cursor_by_index(t_link **alk, int index);

char			*ft_strreald(char *s1, char *s2);
char			*ft_strreal(char *s1, char *s2);

void			mv_top(int is_pila, int index, t_pset *pset);
void			add_one_ope(char *ope, t_pset *pset);
void			ope_route(t_pset *pset, char *cmd);
void			pushall_isna(int is_pila, t_pset *pset);

void			sort_small(int is_pila, t_pset *pset);

int				find_mid_pile(t_link *pile, int size, int min, int max);
int				find_mid_pile2(t_link *pile, int size, int min, int max);
int				find_midd(int is_pila, t_pset *pset);
void			split_pile(int is_pila, t_pset *pset);
int				get_max_six_times_two(int is_pila, t_pset *pset);
int				get_min_max_mid(int is_pila, t_pset *pset);
int				get_set_pack_size(int is_pila, t_pset *pset);
t_pset			*split_pack(int is_pila, t_pset *pset);
int				split_pack_rec(int is_pila, t_pset *pset);

void			three_left_sort(int is_pila, t_pset *pset, int nsort);
void			three_left_nsort(int is_pila, t_pset *pset);
#endif
