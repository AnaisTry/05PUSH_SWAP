/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:36:42 by angassin          #+#    #+#             */
/*   Updated: 2023/03/30 16:46:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_node *lst);

void	sort(t_stack *stack)
{
	if (is_sorted(stack->a) == true)
		return ;
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
