/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:22:16 by angassin          #+#    #+#             */
/*   Updated: 2023/04/01 13:08:21 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	Allocates (with malloc(3)) and returns a new node
	containing the value given in argument. 
*/
t_node	*newnode(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

// Returns the last node of the list.
t_node	*lastnode(t_node *node)
{
	if (!node)
		return (NULL);
	while (node && node->next)
		node = node->next;
	return (node);
}

// Adds the node ’new’ at the end of the list.
void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = lastnode(*lst);
		last->next = new;
	}
}

// Iterates the list and applies the function ’f’ on the content of each node.
void	nodes_iter(t_node *node, void (*f)(int))
{
	if (!node || !f)
		return ;
	while (node)
	{
		f(node->value);
		node = node->next;
	}	
}

// Returns the length of the list aka the number of nodes in the list.
int	lstsize(t_node *node)
{
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node != NULL)
	{
		node = node->next;
		len++;
	}
	return (len);
}
