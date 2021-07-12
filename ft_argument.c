/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:54 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/12 15:33:08 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_argument	validate_argument(int argc, char **argv)
{
	t_argument	argument;
	int			i;
	int			j;

	if (argc == 1)
		print_error();
	argument = make_argument(argc, argv);
	argument.tab = malloc((argument.size) * sizeof(int));
	if (!argument.tab)
		exit(2);
	i = -1;
	while (++i < argument.size)
		argument.tab[i] = ft_atoi_2(argument.arg[i]);
	i = -1;
	while (++i < argument.size - 1)
	{
		j = i;
		while (++j < argument.size)
		{
			if (argument.tab[i] == argument.tab[j])
				print_error();
		}
	}
	//argument = find_medians(argument);
	return (argument);
}

t_argument	make_argument(int argc, char **argv)
{
	t_argument	argument;
	char		*argument_chain;
	int			i;

	argument.size = 0;
	i = 0;
	argument_chain = NULL;
	while (++i < argc)
	{
		if (!argument_chain)
			argument_chain = ft_strdup(argv[i]);
		else
			argument_chain = ft_strjoin(argument_chain, argv[i]);
	}
	argument.arg = ft_split(argument_chain, ' ');
	i = 0;
	while (argument.arg[argument.size] != NULL)
		argument.size++;
	if (argument.size < 2)
		print_error();
	return (argument);
}

void	create_pile(t_pile *pile, int new_nb)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof (t_element));
	if (!new)
		exit(EXIT_FAILURE);
	new->nb = new_nb;
	new->next = pile->first;
	pile->first = new;
}
