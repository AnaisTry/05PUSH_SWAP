/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:11:59 by angassin          #+#    #+#             */
/*   Updated: 2023/04/04 18:40:50 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    radix_sort(t_stack *stack)
{
    size_t  i;
    size_t  j;
    size_t  stack_size_total;
    int nb;

    stack_size_total = stack->size;
    i = 0;
    while (!is_sorted(stack->a))
    {
        j = 0;
        {
            nb = stack->a->index;
            if ((nb >> i) & 1)
                rotate(&stack->a, 'a');
            else
            {
                push(&stack->b, &stack->a, 'b');
                stack->size--;
            }
            j++;
        }
        while (stack->size < stack_size_total)
        {
            push(&stack->a, &stack->b, 'a');
            stack->size++;
        }
        ++i;
    }
}