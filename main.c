/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:56:11 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/09 19:46:24 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_argument	argument;
	t_pile		*pile_a;
	t_pile		*pile_b;
	int			i;

	pile_a = NULL;
	pile_b = NULL;
	argument = validate_argument(argc, argv);
	pile_a = initialize_pile(pile_a);
	pile_b = initialize_pile(pile_b);
	i = argument.size;
	while (i-- > 0)
		insert_top(pile_a, argument.tab[i]);
	printf("PILE A\n"); /* delete */
	print_pile(pile_a); /* delete */
	// pile_tab_median(pile_a); /* delete */
	// printf("median = %d\n", pile_a->median); /* delete */
	printf("algoooo!\n");
	algo(*pile_a, *pile_b);
	return(0);
}

int	algo(t_pile pile_a, t_pile pile_b)
{
	t_element	*current_a;
	// t_element	*current_b;
	int			i;

	i = 0;
	pile_a = *ft_lstsize(&pile_a);
	if (pile_a.size > 3)
	{
		pile_tab_median(&pile_a);
		current_a = pile_a.first;
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
		exit (0);
	printf("PILE A\n"); /* delete */
	print_pile(&pile_a); /* delete */
	printf("PILE B\n"); /* delete */
	print_pile(&pile_b); /* delete */
	algo(pile_a, pile_b);
	return (0);
}
