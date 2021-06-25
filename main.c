#include "push_swap.h"

int main(int argc, char **argv)
{
	t_argument	argument;
	t_pile		*pile_a;
	t_pile		*pile_b;
	int			i; /* delete */

	argument = validate_argument(argc, argv);
	pile_a = initialize_pile(pile_a);
	pile_b = initialize_pile(pile_b);
	i = argument.nb; /* delete */
	while (i-- > 0)
		insert_top(pile_a, argument.tab[i]);
	print_pile(pile_a);
	return(0);
}