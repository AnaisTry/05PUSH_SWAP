/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:25 by angassin          #+#    #+#             */
/*   Updated: 2023/03/29 16:44:07 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	init(char **av, t_stack *stack);
static	void	arg_is_valid(const char *arg);
static	void	is_valid_int(char *arg, int value);

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
		is_valid_int(av[i], value);
		node_add_back(&stack->a, newnode(value));
	}
}

/* 
	Checks that the argument contains only digits and only one minus sign
	before the digits if there is one
*/
static void	arg_is_valid(const char *arg)
{
	size_t	i;

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
}

/* uses the return value of atoi to check if value is an integer */
static void	is_valid_int(char *arg, int value)
{
	ft_printf("value : %d\n", value);

	if (value == 0 && !(ft_strncmp(arg, "0", ft_strlen(arg)) == 0))
		error_exit();
	if (value == -1 && !(ft_strncmp(arg, "-1", ft_strlen(arg)) == 0))
		error_exit();
}
