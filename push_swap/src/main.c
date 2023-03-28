/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:25 by angassin          #+#    #+#             */
/*   Updated: 2023/03/28 17:49:50 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	init(char **av, t_stack *stack);

int	main(int argc, char	**argv)
{
	t_stack	stack;

	if (argc < 2)
		return (EXIT_FAILURE);
	init(argv, &stack);
	int i = 0;
	while (stack.a)
	{
		ft_printf("node %d : %d\n", i, stack.a->value);
		stack.a = stack.a->next;
		i++;
	}
	return (0);
}

static void	init(char **av, t_stack *stack)
{
	size_t	i;

	i = 0;
	stack->a = NULL;
	stack->b = NULL;
	if (av[1] == NULL)
		exit(WRONG_ARG);
	while (av[++i])
	{
		if (arg_is_valid(av[i]) = true)
			node_add_back(&stack->a, newnode(ft_atoi(av[i])));
	}
}
