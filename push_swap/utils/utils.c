/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:01:24 by angassin          #+#    #+#             */
/*   Updated: 2023/04/01 14:09:49 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
	Displays "Error" followed by a ’\n’ on the standard error 
	and exit	
*/
void	error_exit(t_stack	*stack)
{
	if (stack)
	{
		lstclear(&stack->a);
		lstclear(&stack->b);
	}
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/* 
	Returns an index number in ascending order according to the value of the node
*/
int	index_order(t_node *node, int value)
{
	int	index;

	index = 0;
	while (node)
	{
		if (value > node->value)
			index++;
		node = node->next;
	}
	return (index);
}
