/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:48:56 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/12 14:58:57 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_tab_median(t_pile *pile)
{
	t_element	*current;
	int			i;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	ft_lstsize(pile);
	pile->tab = malloc(pile->size * sizeof(int));
	if (!pile->tab)
		exit(2);
	i = 0;
	current = pile->first;
	while (current != NULL)
	{
		pile->tab[i] = current->nb;
		current = current->next;
		i++;
	}
	pile = pile_median(pile);
	return (pile);
}

void	ft_lstsize(t_pile *pile)
{
	int			i;
	t_element	*current;

	i = 0;
	current = pile->first;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	pile->size = i;
}

t_pile	*pile_median(t_pile *pile)
{
		int	swap;
	int	i;

	i = 0;
	while (i < (pile->size - 1))
	{
		if (pile->tab[i] > pile->tab[i + 1])
		{
			swap = pile->tab[i];
			pile->tab[i] = pile->tab[i + 1];
			pile->tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	if (pile->size % 2 != 0)
		i = (pile->size - 1) / 2;
	else
		i = pile->size / 2;
	pile->median = pile->tab[i - 1];
	pile->i = i;
	return (pile);
}