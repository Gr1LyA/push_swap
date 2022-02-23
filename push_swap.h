/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:49:30 by tharland          #+#    #+#             */
/*   Updated: 2021/09/10 19:49:32 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_num
{
	int			min;
	int			middle;
	int			max;
	int			count_b;
}				t_num;

typedef struct s_stack
{
	int			*a;
	int			*b;
}				t_stack;

void			sorted_x5(t_stack stack, int count, t_num num);
int				check_dubl(int *a, int argc);
int				check_argv(int argc, char **argv);
void			operations_main(t_stack stack, int count);
void			rrr(int *a, int *b, int count, int count_b);
void			sa(int *a, int count, int count_b);
void			sb(int *b, int count_b);
void			ss(int *a, int *b, int count, int count_b);
void			pa(int *a, int *b, int count, int *count_b);
void			pb(int *a, int *b, int count, int *count_b);
void			ra(int *a, int count, int count_b);
void			rb(int *b, int count_b);
void			rr(int *a, int *b, int count, int count_b);
void			rra(int *a, int count, int count_b);
void			rrb(int *b, int count_b);
int				check_sort(int *a, int count);
void			sorted_x3(int *a, int count, t_num num);
void			min_max(int *a, int count, t_num *num);
int				*sort(int *a, int count);
long int		ft_atoi2(const char *str);
void			push_a(t_stack stack, int count, t_num *num, t_num info_chunk);
void			sub_rb_or_rrb(t_stack stack, t_num *num, int tmp);
void			rb_or_rrb(t_stack stack, t_num *num);
void			push_b(t_stack stack, t_num info_chunk, t_num *num, int count);

#endif
