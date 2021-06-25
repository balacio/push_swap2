/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medians.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:40:20 by joagosti          #+#    #+#             */
/*   Updated: 2021/06/25 20:46:06 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_argument	*ft_sort_int_tab(t_argument argument)
{
	int	size;
	int	i;
	int	j;
	int	temp;

	size = argc - 1;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (*(tab + j) < *(tab + i))
			{
				temp = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	ft_median(int argc)
{
	int	i;
	int	median;

	if (argc % 2 != 0)
		i = argc / 2 + 1 / 2;
	else
		i = argc / 2;
	return (i);
}
