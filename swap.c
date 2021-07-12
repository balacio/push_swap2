/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:14:18 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/12 16:01:57 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile *pile)
{
	int	swap;
	int	swing;

	swap = pile->first->nb;
	swing = pile->first->next->nb;
	pile->first->nb = swing;
	pile->first->next->nb = swap;
	// write(1, "sa\n", 3); /* send to chained list */
}

void	swap_b(t_pile *pile)
{
	int	swap;
	int	swing;

	swap = pile->first->nb;
	swing = pile->first->next->nb;
	pile->first->nb = swing;
	pile->first->next->nb = swap;
	// write(1, "sb\n", 3); /* send to chained list */
}

void	swap_s(t_pile *pile_a, t_pile *pile_b)
{
	swap_a(pile_a);
	swap_b(pile_b);
	// write(1, "ss\n", 3); /* send to chained list */
}
