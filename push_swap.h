/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:39:31 by rosman            #+#    #+#             */
/*   Updated: 2024/02/24 22:34:36 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define PRINT_ERROR 1
# define JUST_FREE 0 
# define JUST_EXIT 2 

# include "ft_printf/ft_printf.h"

typedef struct node
{
	int			content;
	int			index;
	struct node	*next;
}	t_node;

typedef struct t_stack
{
	struct node	*top;
}	t_stack;

#endif