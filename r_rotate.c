/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:41:25 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/09 19:21:57 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_pile *pile_a)
{
	t_element	*actuel;
	int			swap;

	if (pile_a == NULL)
		exit(EXIT_FAILURE);
	actuel = pile_a->first;
	while (actuel->next != NULL)
		actuel = actuel->next;
	swap = actuel->nb;
	insert_top(pile_a, swap);
	delete_bottom(pile_a);
	// write(1, "rra\n", 4); /* send to chained list */
}

void	r_rotate_b(t_pile *pile_b)
{
	t_element	*actuel;
	int			swap;

	if (pile_b == NULL)
		exit(EXIT_FAILURE);
	actuel = pile_b->first;
	while (actuel->next != NULL)
		actuel = actuel->next;
	swap = actuel->nb;
	insert_top(pile_b, swap);
	delete_bottom(pile_b);
	// write(1, "rrb\n", 4); /* send to chained list */
}

void	r_rotate_r(t_pile *pile_a, t_pile *pile_b)
{
	r_rotate_a(pile_a);
	r_rotate_b(pile_b);
	// write(1, "rrr\n", 4); /* send to chained list */
}
