/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:25 by angassin          #+#    #+#             */
/*   Updated: 2023/03/27 15:43:01 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void    init(char **av, t_stack *stack);

int	main(int argc, char	**argv)
{
    t_stack stack;

    if (argc < 2)
        return (EXIT_FAILURE);

    init(argv, &stack);
    
    return (0);
}

static void    init(char **av, t_stack *stack)
{
    size_t  i;

    i = 0;
    stack->a = NULL;
    stack->b = NULL;
    if (av[1] ==  NULL)
        exit(WRONG_ARG);
    while(av[++i])
        ft_lstadd_back(&stack->a, ft_lstnew((void *)ft_atoi(av[i])));
    // check content :
    ft_lstiter(stack->a, ft_printf("stack a : \n%d\n", (int)stack->a->content));
    
    stack->size = ft_lstsize(stack->a);
    
}
