/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:48:23 by tharland          #+#    #+#             */
/*   Updated: 2021/09/10 19:48:25 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int count, int count_b)
{
	int	tmp;

	write(1, "sa\n", 3);
	if (count - count_b >= 2)
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
}

void	sb(int *b, int count_b)
{
	int	tmp;

	write(1, "sb\n", 3);
	if (count_b >= 2)
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
}

void	ss(int *a, int *b, int count, int count_b)
{
	write(1, "ss\n", 3);
	sa(a, count, count_b);
	sb(b, count_b);
}

void	pa(int *a, int *b, int count, int *count_b)
{
	int	i;

	write(1, "pa\n", 3);
	count--;
	if (*count_b > 0)
	{
		while (count > 0)
		{
			a[count] = a[count - 1];
			count--;
		}
		a[0] = b[0];
		i = 0;
		while (i < (*count_b) - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		(*count_b)--;
	}
}

void	pb(int *a, int *b, int count, int *count_b)
{
	int	i;

	write(1, "pb\n", 3);
	if (*count_b != count)
	{
		i = (*count_b);
		while (i > 0)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[0] = a[0];
		i = 0;
		while (i < count - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		(*count_b)++;
	}
}
