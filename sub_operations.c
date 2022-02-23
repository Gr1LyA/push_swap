/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:50:07 by tharland          #+#    #+#             */
/*   Updated: 2021/09/10 19:50:09 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *a, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sub_sorted_x3(int *a, int i, int count, t_num num)
{
	if (i == 0 && a[count - 1] == num.min)
	{
		sa(a, count, num.count_b);
		rra(a, count, num.count_b);
	}
	else if (i == 1 && a[0] == num.min)
	{
		sa(a, count, num.count_b);
		ra(a, count, num.count_b);
	}
	else if (i == 2 && a[1] == num.min)
		sa(a, count, num.count_b);
	i = 0;
	while (a[i] != num.min)
		i++;
	while (i > 2 && num.min != a[0])
		rra(a, count, num.count_b);
	while (i <= 2 && num.min != a[0])
		ra(a, count, num.count_b);
}

void	sorted_x5(t_stack stack, int count, t_num num)
{
	int	*sort_a;
	int	i;

	sort_a = sort(stack.a, count);
	min_max(sort_a, count, &num);
	while (num.count_b != 2)
	{
		i = 0;
		while (num.min != stack.a[i] && num.max != stack.a[i])
			i++;
		while (i <= 2 && num.min != stack.a[0] && num.max != stack.a[0])
			ra(stack.a, count, num.count_b);
		while (i > 2 && num.min != stack.a[0] && num.max != stack.a[0])
			rra(stack.a, count, num.count_b);
		pb(stack.a, stack.b, count, &(num.count_b));
	}
	sorted_x3(stack.a, count - num.count_b, num);
	if (stack.b[0] != num.min)
		sb(stack.b, num.count_b);
	pa(stack.a, stack.b, count, &(num.count_b));
	pa(stack.a, stack.b, count, &(num.count_b));
	ra(stack.a, count, num.count_b);
}

void	sorted_x3(int *a, int count, t_num num)
{
	int	*sort_a;
	int	i;

	num.count_b = 0;
	sort_a = sort(a, count);
	min_max(sort_a, count, &num);
	i = 0;
	while (a[i] != num.max)
		i++;
	sub_sorted_x3(a, i, count, num);
}

void	min_max(int *sort_a, int count, t_num *num)
{
	(*num).min = sort_a[0];
	(*num).max = sort_a[count - 1];
	(*num).middle = sort_a[count / 2];
}
