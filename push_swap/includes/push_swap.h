/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:11:37 by angassin          #+#    #+#             */
/*   Updated: 2023/04/06 17:08:44 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*									[Includes]								*/

// read, write, STDERR_FILENO
# include <unistd.h>
// exit, malloc, free, size_t
# include <stdlib.h>
// libft
# include "../libft/includes/libft.h"
# include "../libft/includes/libftprintf.h"
# include "../libft/includes/get_next_line.h"

/*									[Macros]								*/

# define WRONG_ARG 2

/*									[Typedefs]								*/

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	size_t	size;
}				t_stack;

/*									[Src]									*/

// sort.c
void	sort(t_stack *stack);
int		is_sorted(t_node *lst);

// operations.c
void	swap(t_node **stack, char stack_name);
void	rotate(t_node **stack, char stack_name);
void	reverse_rotate(t_node **stack, char stack_name);
void	push(t_node **dest, t_node **src, char stack_name);

// radix_sort.c
void	radix_sort(t_stack *stack);

/*									[Utils]									*/

// utils.c
void	error_exit(t_stack *stack);
int		index_order(t_node *node, int value);
int		ranking(t_node *node, int index);
int		find_min(t_node *node);
#endif
