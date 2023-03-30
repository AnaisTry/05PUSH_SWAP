/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:01:24 by angassin          #+#    #+#             */
/*   Updated: 2023/03/30 11:41:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
	Displays "Error" followed by a ’\n’ on the standard error 
	and exit	
*/
void	error_exit(void)
{
	//if 
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
