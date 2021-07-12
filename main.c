/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:56:11 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/12 18:31:04 by joagosti         ###   ########.fr       */
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
	printf("\nArg Valid\n"); /* delete */
	argument = validate_argument(argc, argv);
	printf("\nInit Pile A\n"); /* delete */
	pile_a = initialize_pile(pile_a);
	printf("\nInit Pile B\n"); /* delete */
	pile_b = initialize_pile(pile_b);
	i = argument.size;
	printf("\nCreate Pile A\n"); /* delete */
	while (i-- > 0)
		create_pile(pile_a, argument.tab[i]);
	current = pile_a->first;
	printf("\nInit Tag\n"); /* delete */
	while (current != NULL)
	{
		current->tag = -1;
		current = current->next;
	}
	printf("\nPILE A\n"); /* delete */
	print_pile(pile_a); /* delete */
	printf("\nALGOOOOOO!!!\n\n");
	if (pile_a->first == NULL)
	{
		printf("\nExit here 3\n"); /* delete */
		exit(2);
	}
	algo(pile_a, pile_b);
	return(0);
}

int	algo(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*current_a;
	t_element	*current_b;

	current_a = pile_a->first;
	current_b = pile_b->first;
	pile_a->size = ft_lstsize_OG(current_a);
	printf("list size pile A = %d\n", pile_a->size);
	pile_b->size = ft_lstsize_OG(current_b);
	printf("list size pile B = %d\n", pile_b->size);
	sort_pile(pile_a, pile_b, current_a);
	printf("\nPILE A\n"); /* delete */
	print_pile(pile_a); /* delete */
	printf("PILE B\n"); /* delete */
	print_pile(pile_b); /* delete */
	ft_lstsize(pile_b);
	if (pile_b->size == 0)
	{
		printf("\nExit here 1\n"); /* delete */
		exit (0);
	}
	else 
		algo(pile_a, pile_b);
	return (0);
}

void	sort_pile(t_pile *pile_a, t_pile *pile_b, t_element *current_a)
{
	int	i;

	i = 0;
	if (pile_a->size > 2)
	{
		pile_tab_median(pile_a);
		while (current_a != NULL && pile_a->i > i)
		{
			if (current_a->nb <= pile_a->median && current_a->tag!=0)
				push_b(pile_a, pile_b);
			else
				rotate_a(pile_a);
			current_a = current_a->next;
			i++;
		}
	}
	else
	{
		current_a = pile_a->first;
		current_a->tag = 0;
		current_a->next->tag = 0;
		if (current_a->nb > current_a->next->nb)
			swap_a(pile_a);
		else 
		{
			printf("\nExit here 2\n"); /* delete */
			exit(0);
		}
	}
}