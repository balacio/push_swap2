/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:28:10 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/12 15:58:55 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pile *pile_a, t_pile *pile_b)
{
	// int	tmp;

	// tmp = pile_b->first->nb;
	insert_top(pile_a, *pile_a->first);
	delete_top(pile_b);
	// write(1, "pa\n", 3); /* send to chained list */
}

void	push_b(t_pile *pile_a, t_pile *pile_b)
{
	// int	tmp;

	// tmp = pile_a->first->nb;
	insert_top(pile_b, *pile_a->first);
	delete_top(pile_a);
	// write(1, "pb\n", 3); /* send to chained list */
}
