/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:47:41 by tharland          #+#    #+#             */
/*   Updated: 2021/09/10 19:47:47 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_main1(t_stack stack, int count, t_num num, int count_chunks)
{
	int		*sort_a;
	int		in_chunk;
	int		border_sort_a;
	t_num	info_chunk;

	sort_a = sort(stack.a, count);
	min_max(sort_a, count, &num);
	in_chunk = count / count_chunks;
	border_sort_a = count;
	while (border_sort_a >= in_chunk)
	{
		min_max(sort_a + border_sort_a - in_chunk, in_chunk, &info_chunk);
		while (num.count_b != in_chunk)
			push_b(stack, info_chunk, &num, count);
		border_sort_a -= in_chunk;
		push_a(stack, count, &num, info_chunk);
	}
	if (border_sort_a == 0)
		return ;
	min_max(sort_a, border_sort_a, &info_chunk);
	while (num.count_b != border_sort_a)
		push_b(stack, info_chunk, &num, count);
	push_a(stack, count, &num, info_chunk);
}

void	operations_main(t_stack stack, int count)
{
	t_num	num;
	int		count_chunks;

	num.count_b = 0;
	if (check_sort(stack.a, count))
		return ;
	if (count == 2)
	{
		if (stack.a[0] > stack.a[1])
			ra(stack.a, count, num.count_b);
		return ;
	}
	else if (count == 3)
		return (sorted_x3(stack.a, count, num));
	else if (count == 4)
		count_chunks = 4;
	else if (count == 5)
		return (sorted_x5(stack, count, num));
	else if (count <= 200)
		count_chunks = 4;
	else if (count <= 500)
		count_chunks = 10;
	else
		count_chunks = 15;
	return (op_main1(stack, count, num, count_chunks));
}

static int	stack_a(char **str, int count)
{
	t_stack	stack;
	int		i;

	stack.a = malloc(sizeof(int) * count);
	stack.b = malloc(sizeof(int) * count);
	if (!stack.a || !stack.b)
		return (0);
	i = 0;
	while (++i <= count)
		stack.a[i - 1] = ft_atoi2(str[i - 1]);
	if (check_dubl(stack.a, count))
		return (0);
	operations_main(stack, count);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**str;
	int		count;

	str = argv + 1;
	count = argc - 1;
	if (count == 0)
		return (0);
	if (check_argv(count, str))
		return (0);
	return (stack_a(str, count));
}
