/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:48:13 by tharland          #+#    #+#             */
/*   Updated: 2021/09/10 19:48:16 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack stack, int count, t_num *num, t_num info_chunk)
{
	static int	previously_min;
	int			i;

	i = 0;
	while (stack.b[i] != info_chunk.max)
		i++;
	while (i <= num->count_b / 2 && stack.b[0] != info_chunk.max)
		rb(stack.b, num->count_b);
	while (i > num->count_b / 2 && stack.b[0] != info_chunk.max)
		rrb(stack.b, num->count_b);
	if (info_chunk.max != num->max)
	{
		i = 0;
		while (stack.a[i] != previously_min)
			i++;
		while (i <= (count - num->count_b) / 2 && stack.a[0] != previously_min)
			ra(stack.a, count, num->count_b);
		while (i > (count - num->count_b) / 2 && stack.a[0] != previously_min)
			rra(stack.a, count, num->count_b);
	}
	while (num->count_b > 0)
		pa(stack.a, stack.b, count, &(num->count_b));
	previously_min = info_chunk.min;
}

void	sub_rb_or_rrb(t_stack stack, t_num *num, int tmp)
{
	int	i;

	i = 0;
	while (stack.b[i] != tmp)
		i++;
	if (stack.a[0] < tmp)
	{
		while (i >= num->count_b / 2 && stack.b[num->count_b - 1] != tmp)
			rrb(stack.b, num->count_b);
		while (i < num->count_b / 2 && stack.b[num->count_b - 1] != tmp)
			rb(stack.b, num->count_b);
	}
	else
	{
		while (i > num->count_b / 2 && stack.b[0] != tmp)
			rrb(stack.b, num->count_b);
		while (i <= num->count_b / 2 && stack.b[0] != tmp)
			rb(stack.b, num->count_b);
	}
}

void	rb_or_rrb(t_stack stack, t_num *num)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack.b[0];
	while (i < num->count_b)
	{
		if (stack.b[i] < tmp)
			tmp = stack.b[i];
		i++;
	}
	i = 0;
	while (i < num->count_b)
	{
		if (stack.b[i] > tmp && stack.b[i] < stack.a[0])
			tmp = stack.b[i];
		i++;
	}
	sub_rb_or_rrb(stack, num, tmp);
}

void	push_b(t_stack stack, t_num info_chunk, t_num *num, int count)
{
	int	i;
	int	j;

	i = 0;
	while (!(stack.a[i] <= info_chunk.max && stack.a[i] >= info_chunk.min))
		i++;
	j = count - num->count_b - 1;
	while (!(stack.a[j] <= info_chunk.max && stack.a[j] >= info_chunk.min))
		j--;
	j = count - num->count_b - 1 - j;
	while (i <= j
		&& (!(stack.a[0] <= info_chunk.max && stack.a[0] >= info_chunk.min)))
		ra(stack.a, count, num->count_b);
	while (j < i
		&& (!(stack.a[0] <= info_chunk.max && stack.a[0] >= info_chunk.min)))
		rra(stack.a, count, num->count_b);
	if (num->count_b != 0)
	{
		rb_or_rrb(stack, num);
	}
	pb(stack.a, stack.b, count, &(num->count_b));
	if (num->count_b == 2 && stack.b[1] == info_chunk.max)
		sb(stack.b, num->count_b);
}

void	rrr(int *a, int *b, int count, int count_b)
{
	write(1, "rrr\n", 4);
	rrb(b, count_b);
	rra(a, count, count_b);
}
