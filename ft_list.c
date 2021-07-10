/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:30:17 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/10 13:35:35 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*initialize_pile(t_pile *pile)
{
	t_element	*element;

	pile = (t_pile *)malloc(sizeof (t_pile));
	element = (t_element *)malloc(sizeof (t_element));
	if ((!pile) || (!element))
		exit(EXIT_FAILURE);
	pile->first = NULL;
	return (pile);
}

void	insert_top(t_pile *pile, int new_nb)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof (t_element));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = new_nb;
	new->next = pile->first;
	pile->first = new;
}

// void	insert_bottom(t_pile *pile, t_element *current, int new_nb)
void	insert_bottom(t_element *current, int new_nb)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof (t_element));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = new_nb;
	new->next = NULL;
	current->next = new;
}

void	delete_top(t_pile *pile)
{
	t_element	*to_delete;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	if (pile->first != NULL)
	{
		to_delete = pile->first;
		pile->first = pile->first->next;
		free(to_delete);
	}
}

void	delete_bottom(t_pile *pile)
{
	t_element	*to_delete;
	t_element	*current;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	if (pile->first != NULL)
	{
		current = pile->first;
		while (current->next->next != NULL)
			current = current->next;
		to_delete = current->next;
		current->next = NULL;
		free(to_delete);
	}
}
