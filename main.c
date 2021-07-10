/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:56:11 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/10 18:44:51 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_argument	argument;
	t_pile		*pile_a;
	t_pile		*pile_b;
	t_element	*current;
	int			i;

	pile_a = NULL;
	pile_b = NULL;
	argument = validate_argument(argc, argv);
	pile_a = initialize_pile(pile_a);
	pile_b = initialize_pile(pile_b);
	i = argument.size;
	while (i-- > 0)
		insert_top(pile_a, argument.tab[i]);
	current = pile_a->first;
	while (current != NULL)
	{
		current->tag = -1;
		current = pile_a->first->next;
	}
	printf("\nPILE A\n"); /* delete */
	print_pile(pile_a); /* delete */
	// pile_tab_median(pile_a); /* delete */
	// printf("median = %d\n", pile_a->median); /* delete */
	printf("\nALGOOOOOO!!!\n\n");
	if (pile_a->first == NULL)
		exit(2);
	algo(*pile_a, *pile_b);
	return(0);
}

int	algo(t_pile pile_a, t_pile pile_b)
{
	t_element	*current_a;
	t_element	*current_b;
	int			i;

	i = 0;
	current_a = pile_a.first;
	current_b = pile_b.first;
	pile_a = *ft_lstsize(&pile_a);
	if (pile_a.size > 3)
	{
		pile_tab_median(&pile_a);
		while (current_a != NULL && pile_a.i > i)
		{
			if (current_a->nb < pile_a.median)
			{
				push_b(&pile_a, &pile_b);
			}
			else
			{
				rotate_a(&pile_a);
			}
			current_a = current_a->next;
			i++;
		}
	}
	else
	{
		current_a = pile_a.first;
		// while (current_a != NULL)
		// {
			// if (current_a < current_a->next && current_a->next < current_a->next->next)
			if (current_a > current_a->next)
				swap_a(&pile_a);
			if (current_a > current_a->next->next)
				r_rotate_a(&pile_a);
			if (current_a->nb < current_a->next->nb < current_a->next->next->nb)
				exit (0);
				// algo(pile_a, pile_b);
		// }
		current_a->tag = 0;
		current_a->next->tag = 0;
		current_a->next->next->tag = 0;
	}
		// exit (0);
	printf("\nPILE A\n"); /* delete */
	print_pile(&pile_a); /* delete */
	printf("PILE B\n"); /* delete */
	print_pile(&pile_b); /* delete */
	algo(pile_a, pile_b);
	return (0);
}
