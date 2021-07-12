/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:10:10 by joagosti          #+#    #+#             */
/*   Updated: 2021/07/12 17:16:14 by joagosti         ###   ########.fr       */
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
	char	**arg;
	int		*tab;
	int		*tab_sort;
	int		size;
	int		pivot1;
}			t_argument;

typedef struct s_element
{
	int					nb;
	int					tag; //0 if sorted
	struct s_element	*next;
}						t_element;

typedef struct s_pile
{
	t_element	*first;
	int			median;
	int			size; //# all variables
	int			i; //current pile size
	int			*tab;
}				t_pile;

// typedef struct s_piles
// {
// 	struct t_pile	*a;
// 	struct t_pile	*b;
// }					t_piles;

typedef struct s_move
{
	char			move;
	struct s_move	*next;
}					t_move;

/* ft_argument.c */
t_argument	validate_argument(int argc, char **argv);
t_argument	make_argument(int argc, char **argv);
void		create_pile(t_pile *pile, int new_nb);

/* ft_error.c */
int			print_error(void);

/* ft_list.c */
t_pile		*initialize_pile(t_pile *pile);
void		insert_top(t_pile *pile, t_element actuel);
// void		insert_bottom(t_pile *pile, t_element *current, int new_nb);
void		insert_bottom(t_element *current, int new_nb);
void		delete_top(t_pile *pile);
void		delete_bottom(t_pile *pile);

/* ft_lstsize.c */
int			ft_lstsize_OG(t_element *lst);

/* ft_move.c */
void		insert_bottom_res(t_move *current, char new_move);

/* ft_pile_median.c */
t_pile		*pile_tab_median(t_pile *pile);
void		ft_lstsize(t_pile *pile);
t_pile		*pile_median(t_pile *pile);

/* ft_split.c */
int			ft_word_count(char *str, char c);
char		*ft_add_word(char **str, char c);
char		**ft_split(char const *s, char c);

/* ft_utils.c */
int			ft_atoi_2(const char *str);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

/* main.c */
int			algo(t_pile *pile_a, t_pile *pile_b);
void		sort_pile(t_pile *pile_a, t_pile *pile_b, t_element *current_a);

/* push.c */
void		push_a(t_pile *pile_a, t_pile *pile_b);
void		push_b(t_pile *pile_a, t_pile *pile_b);

/* r_rotate.c */
void		r_rotate_a(t_pile *pile_a);
void		r_rotate_b(t_pile *pile_b);
void		r_rotate_r(t_pile *pile_a, t_pile *pile_b);

/* rotate.c */
void		rotate_a(t_pile *pile_a);
void		rotate_b(t_pile *pile_b);
void		rotate_r(t_pile *pile_a, t_pile *pile_b);

/* swap.c */
void		swap_a(t_pile *pile);
void		swap_b(t_pile *pile);
void		swap_s(t_pile *pile_a, t_pile *pile_b);

/* zzz_display.c */
void		print_pile(t_pile *pile);

#endif
