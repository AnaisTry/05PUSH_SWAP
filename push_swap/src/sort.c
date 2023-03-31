/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:36:42 by angassin          #+#    #+#             */
/*   Updated: 2023/03/31 18:09:10 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_node *lst);
static void	sort_3(t_stack *stack);

void	sort(t_stack *stack)
{
	if (is_sorted(stack->a) == TRUE)
		return ;
	if (stack->size == 2)
		swap(&stack->a, 'a');
	else if (stack->size == 3)
		sort_3(stack);
}

static int	is_sorted(t_node *lst)
{
	if (!lst)
		return (-1);
	while (lst->next != NULL)
	{
		if (lst->value > (lst->next)->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/*
	For values a b c :

	if		a > b && b < c
				if a < c
					swap
				else
					rotate
	else if a < b
				reverse
				if !sorted
					swap
	else
				swap
				reverse
*/
static void	sort_3(t_stack *stack)
{
	if (stack->a->value > stack->a->next->value
		&& (stack->a->next)->value < ((stack->a->next)->next)->value)
	{
		if (stack->a->value < ((stack->a->next)->next)->value)
			swap(&stack->a, 'a');
		else
			rotate(&stack->a, 'a');
	}
	else if (stack->a->value < stack->a->next->value)
	{
		reverse_rotate(&stack->a, 'a');
		if (!is_sorted(stack->a))
			swap(&stack->a, 'a');
	}
	else
	{	
		swap(&stack->a, 'a');
		reverse_rotate(&stack->a, 'a');
	}
}
