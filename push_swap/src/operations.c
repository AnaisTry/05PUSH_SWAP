/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:02:50 by angassin          #+#    #+#             */
/*   Updated: 2023/04/03 13:19:16 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **stack, char stack_name)
{
	t_node	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	ft_printf("s%c\n", stack_name);
}

/* First node becomes last  a b c -> b c a */
void	rotate(t_node **stack, char stack_name)
{
	t_node	*first;

	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	node_add_back(stack, first);
	ft_printf("r%c\n", stack_name);
}

/* Last node becomes first a b c -> c a b */
void	reverse_rotate(t_node **stack, char stack_name)
{
	t_node	*last;

	last = *stack;
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = *stack;
	*stack = last->next;
	last->next = NULL;
	ft_printf("rr%c\n", stack_name);
}

void	push(t_node **dest, t_node **src, char stack_name)
{
	t_node	*temp;

	temp = (*src)->next;
	node_add_front(dest, *src);
	(*src) = temp;
	ft_printf("p%c\n", stack_name);
}
