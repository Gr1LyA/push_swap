/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:49:48 by tharland          #+#    #+#             */
/*   Updated: 2021/09/10 19:49:49 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	unsigned char			*s1;
	const unsigned char		*s2;
	size_t					i;

	if (dest == NULL && source == NULL)
		return (NULL);
	s1 = (unsigned char *)dest;
	s2 = (const unsigned char *)source;
	i = 0;
	while (i < count)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}

int	*sort(int *a, int count)
{
	int	i;
	int	j;
	int	tmp;
	int	*sort_a;

	i = 0;
	sort_a = malloc(sizeof(int) * count);
	if (!sort_a)
		exit(0);
	ft_memcpy(sort_a, a, sizeof(int) * count);
	while (i < count)
	{
		j = i;
		while (++j < count)
		{
			if (sort_a[j] < sort_a[i])
			{
				tmp = sort_a[i];
				sort_a[i] = sort_a[j];
				sort_a[j] = tmp;
			}
		}
		i++;
	}
	return (sort_a);
}
