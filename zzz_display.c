/* ZZZ DISPLAY */

#include "push_swap.h"

void	print_pile(t_pile *pile)
{
	t_element	*current;
	int			i;

	i = 0;
	if (pile == NULL)
		exit(EXIT_FAILURE);
	current = pile->first;
	while (current != NULL)
	{
		printf("%d -> ", current->nb);
		current = current->next;
		i++;
	}
	printf("NULL\n");
}
