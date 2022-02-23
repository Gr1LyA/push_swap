/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:48:37 by tharland          #+#    #+#             */
/*   Updated: 2021/09/10 19:48:38 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *a, int count, int count_b)
{
	int	tmp;
	int	i;

	write(1, "ra\n", 3);
	count -= count_b;
	tmp = a[0];
	i = 0;
	while (i < count - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[count - 1] = tmp;
}

void	rb(int *b, int count_b)
{
	int	tmp;
	int	i;

	write(1, "rb\n", 3);
	tmp = b[0];
	i = 0;
	while (i < count_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[count_b - 1] = tmp;
}

void	rr(int *a, int *b, int count, int count_b)
{
	write(1, "rr\n", 3);
	ra(a, count, count_b);
	rb(b, count_b);
}

void	rra(int *a, int count, int count_b)
{
	int	tmp;
	int	i;

	write(1, "rra\n", 4);
	count -= count_b;
	tmp = a[count - 1];
	i = count;
	while (--i > 0)
		a[i] = a[i - 1];
	a[0] = tmp;
}

void	rrb(int *b, int count_b)
{
	int	tmp;
	int	i;

	write(1, "rrb\n", 4);
	tmp = b[count_b - 1];
	i = count_b;
	while (--i > 0)
		b[i] = b[i - 1];
	b[i] = tmp;
}
