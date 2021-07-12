/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:32:05 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/12 14:45:19 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_bottom_res(t_move *current, char new_move)
{
	t_move	*new;

	new = (t_move *)malloc(sizeof (t_move));
	if (!new)
		exit(EXIT_FAILURE);
	new->move = new_move;
	new->next = NULL;
	current->next = new;
}