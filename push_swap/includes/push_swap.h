/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:11:37 by angassin          #+#    #+#             */
/*   Updated: 2023/03/27 15:17:13 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*									[Includes]								*/

// read, write
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

typedef struct s_stack
{
    t_list  *a;
    t_list  *b;
    size_t  size;
}               t_stack;



/*									  [Src]	    							*/


/*									[Utils]	    							*/

#endif