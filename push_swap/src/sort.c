/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:36:42 by angassin          #+#    #+#             */
/*   Updated: 2023/04/04 00:09:01 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_node *lst);
static void	sort_3(t_stack *stack);
// static void	sort_4(t_stack *stack);
void	sort_small_stack(t_stack *stack);

void	sort(t_stack *stack)
{
	if (is_sorted(stack->a) == TRUE)
		return ;
	if (stack->size == 2)
		swap(&stack->a, 'a');
	else if (stack->size == 3)
		sort_3(stack);
	else if (stack->size == 4)
		sort_small_stack(stack);
		//sort_4(stack);
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

/* 
	Find the place of the smallest number
	Put it on top of the stack

*/
// static void	sort_4(t_stack *stack)
// {
// 	int	min;
// 	int	min_rank;

// 	min = 0;
// 	min_rank = ranking(stack->a, min);
// 	if (min_rank <= 3)
// 		while (stack->a->index != min)
// 			rotate(&stack->a, 'a');
// 	else //if (min_rank <= 3)
// 		while (stack->a->index != min)
// 			reverse_rotate(&stack->a, 'a');
// 	push(&stack->b, &stack->a, 'b');
// 	if (!is_sorted(stack->a))
// 		sort_3(stack);
// 	push(&stack->a, &stack->b, 'a');
// }

static void	min_to_top(t_stack *stack)
{
	int	min;
	int	min_rank;

	min = 0;
	min_rank = ranking(stack->a, min);
	if (min_rank < (int)stack->size / 2)
		while (stack->a->index != min)
			rotate(&stack->a, 'a');
	else
		while (stack->a->index != min)
			reverse_rotate(&stack->a, 'a');
}

void	sort_small_stack(t_stack *stack)
{
	size_t	i;

	while (!is_sorted(stack->a))
	{
		if (stack->size == 2)
		{
			swap(&stack->a, 'a');
			break ;
		}
		min_to_top(stack);
		push(&stack->b, &stack->a, 'b');
	}
	i = 0;
	while (i < stack->size)
	{
		push(&stack->a, &stack->b, 'a');
	}
}