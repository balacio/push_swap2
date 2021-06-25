/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:54 by joagosti          #+#    #+#             */
/*   Updated: 2021/06/25 20:41:46 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_argument	validate_argument(int argc, char **argv)
{
	t_argument	argument;
	int			i;
	int 		j;

	if (argc == 1)
		print_error();
	argument = make_argument(argc, argv);
	argument.tab = malloc((argument.nb) * sizeof(int));
	if (!argument.tab)
		exit(2);
	i = -1;
	while (++i < argument.nb)
		argument.tab[i] = ft_atoi_2(argument.arg[i]);
	i = -1;
	while (++i < argument.nb - 1)
	{
		j = i;
		while (++j < argument.nb)
		{
			if (argument.tab[i] == argument.tab[j])
				print_error();
		}
	}
	return(argument);
}

t_argument	make_argument(int argc, char **argv)
{
	t_argument	argument;
	char 		*argument_chain;
	int			i;
	
	argument.nb = 0;
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
	while (argument.arg[argument.nb] != NULL)
		argument.nb++;
	if (argument.nb < 2)
		print_error();
	argument = find_medians(argument);
	return (argument);
}

t_argument	find_medians(t_argument argument)
{
	
	return (argument);
}