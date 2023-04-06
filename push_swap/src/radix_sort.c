/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:11:59 by angassin          #+#    #+#             */
/*   Updated: 2023/04/06 09:51:12 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Radix sort in binary.
	As long as the numbers are not sorted :
		Send all the numbers which binary value finishes by 0 on the stack_b.
		Put back the numbers on stack_a.
		Right shift to get the next unit and repeat the same
		process.
*/
void radix_sort(t_stack *stack)
{
	size_t shift;
	size_t i;
	size_t stack_size_total;
	int nb;

	stack_size_total = stack->size;
	shift = 0;
	while (!is_sorted(stack->a))
	{
		i = 0;
		while (i < stack_size_total)
		{
			nb = stack->a->index;
			if ((nb >> shift) & 1)
				rotate(&stack->a, 'a');
			else
			{
				push(&stack->b, &stack->a, 'b');
				stack->size--;
			}
			i++;
		}
		while (stack->size < stack_size_total)
		{
			push(&stack->a, &stack->b, 'a');
			stack->size++;
		}
		++shift;
	}
}