/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:25 by angassin          #+#    #+#             */
/*   Updated: 2023/04/01 13:05:18 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init(char **av, t_stack *stack);
static void	arg_is_valid(const char *arg);
static void	check_duplicates(t_stack *stack);
static void	assign_index(t_stack *stack);

int	main(int argc, char	**argv)
{
	t_stack	stack;

	if (argc < 2)
		return (EXIT_FAILURE);
	init(argv, &stack);
	check_duplicates(&stack);
	assign_index(&stack);
	sort(&stack);
	if (stack.a)
		lstclear(&stack.a);
	if (stack.b)
		lstclear(&stack.b);
	return (0);
}

/* 
	Initialize the stacks and the nodes, 
	checking that they contain only valid integers
*/
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
		arg_is_valid(av[i]);
		node_add_back(&stack->a, newnode(ft_atoi(av[i])));
	}
	stack->size = lstsize(stack->a);
}

/* 
	Checks that the argument contains only digits, only one minus sign
	before the digits if there is one and that it is an integer
*/
static void	arg_is_valid(const char *arg)
{
	size_t	i;
	long	nb;

	i = 0;
	if (arg[i] == '\0')
		error_exit(NULL);
	if (arg[0] == '-')
		++i;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit(NULL);
		i++;
	}
	if (i == 1 && arg[0] == '-')
		error_exit(NULL);
	nb = ft_atol(arg);
	if (nb < INT_MIN || nb > INT_MAX)
		error_exit(NULL);
}

static void	check_duplicates(t_stack *stack)
{
	t_node	*cursor;
	t_node	*next_node;

	cursor = stack->a;
	while (cursor != NULL)
	{
		next_node = cursor->next;
		while (next_node)
		{
			if (cursor->value == next_node->value)
				error_exit(stack);
			next_node = next_node->next;
		}
		cursor = cursor->next;
	}
}

static void	assign_index(t_stack *stack)
{
	size_t	i;
	t_node	*temp;

	i = 0;
	temp = stack->a;
	while (i < stack->size)
	{
		temp->index = order_index(stack->a, temp->value);
		temp = temp->next;
		i++;
	}
}
