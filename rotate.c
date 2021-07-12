/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:41:25 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/12 16:01:57 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pile *pile_a)
{
	t_element	*actuel;
	int			swap;

	if (pile_a == NULL)
		exit(EXIT_FAILURE);
	swap = pile_a->first->nb;
	actuel = pile_a->first;
	while (actuel->next != NULL)
		actuel = actuel->next;
	insert_bottom(actuel, swap);
	delete_top(pile_a);
	// write(1, "ra\n", 3); /* send to chained list */
}

void	rotate_b(t_pile *pile_b)
{
	t_element	*actuel;
	int			swap;

	if (pile_b == NULL)
		exit(EXIT_FAILURE);
	swap = pile_b->first->nb;
	actuel = pile_b->first;
	while (actuel->next != NULL)
		actuel = actuel->next;
	insert_bottom(actuel, swap);
	delete_top(pile_b);
	// write(1, "rb\n", 3); /* send to chained list */
}

void	rotate_r(t_pile *pile_a, t_pile *pile_b)
{
	rotate_a(pile_a);
	rotate_b(pile_b);
	// write(1, "rr\n", 3); /* send to chained list */
}
