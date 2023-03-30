/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:25 by angassin          #+#    #+#             */
/*   Updated: 2023/03/30 11:00:56 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	init(char **av, t_stack *stack);
static	void	arg_is_valid(const char *arg);

int	main(int argc, char	**argv)
{
	t_stack	stack;

	if (argc < 2)
		return (EXIT_FAILURE);
	init(argv, &stack);
	return (0);
}

/* 
	Initialize the stacks and the nodes, 
	checking that they contain only valid integers
*/
static void	init(char **av, t_stack *stack)
{
	size_t	i;
	int		value;

	i = 0;
	stack->a = NULL;
	stack->b = NULL;
	if (av[1] == NULL)
		exit(WRONG_ARG);
	while (av[++i])
	{
		arg_is_valid(av[i]);
		value = ft_atoi(av[i]);
		node_add_back(&stack->a, newnode(value));
	}
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
		error_exit();
	if (arg[0] == '-')
		++i;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit();
		i++;
	}
	if (i == 1 && arg[0] == '-')
		error_exit();
	nb = ft_atol(arg);
	if (nb < INT_MIN || nb > INT_MAX)
		error_exit();
}
