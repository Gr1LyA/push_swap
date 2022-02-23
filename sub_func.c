/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:49:57 by tharland          #+#    #+#             */
/*   Updated: 2021/09/10 19:49:58 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	sub_ft_atoi2(const char *str, long int res, int znak)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (res * znak < -2147483648 || res * znak > 2147483647 || i == 0 || i > 11)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (res * znak);
}

long int	ft_atoi2(const char *str)
{
	long int	res;
	int			znak;

	znak = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		znak *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (sub_ft_atoi2(str, res, znak));
}

int	check_argv(int argc, char **argv)
{
	int	i;

	argc -= 1;
	while (argc >= 0)
	{
		i = 0;
		if (argv[argc][i] == '-' || argv[argc][i] == '+')
			i++;
		while (argv[argc][i])
		{
			if (argv[argc][i] < '0' || argv[argc][i] > '9')
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			i++;
		}
		argc--;
	}
	return (0);
}

int	check_dubl(int *a, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < i)
		{
			if (a[i] == a[j])
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
