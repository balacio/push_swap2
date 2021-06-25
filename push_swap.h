/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:10:10 by joagosti          #+#    #+#             */
/*   Updated: 2021/06/25 20:41:48 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_argument
{
	char		**arg;
	int			*tab;
	int			nb;
	int			med1;
	int			med2;
	int			med3;
}				t_argument;

typedef struct 			s_element
{
	int					nb;
	struct s_element	*next;
}						t_element;

typedef struct 		s_pile
{
	t_element		*first;
}					t_pile;

typedef struct 		s_piles
{
	t_pile			*a;
	t_pile			*b;
}					t_piles;

/* ft_argument.c */
t_argument 	validate_argument(int argc, char **argv);
t_argument	make_argument(int argc, char **argv);

/* ft_error.c */
int 		print_error(void);

/* ft_list.c */
t_pile		*initialize_pile(t_pile *pile);
void		insert_top(t_pile *pile, int new_nb);
void		insert_bottom(t_pile *pile, t_element *current, int new_nb);
void		delete_top(t_pile *pile);
void		delete_bottom(t_pile *pile);

/* ft_medians.c */

/* ft_split.c */
int			ft_word_count(char *str, char c);
char		*ft_add_word(char **str, char c);
char		**ft_split(char const *s, char c);

/* ft_utils.c */
int			ft_atoi_2(const char *str);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

/* zzz_display.c */
void		print_pile(t_pile *pile);

#endif
