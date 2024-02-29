/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:57:59 by rosman            #+#    #+#             */
/*   Updated: 2024/02/28 22:26:10 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *node)
{
	int		len;
	t_node	*curr;

	len = 0;
	curr = node;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

t_node	*ft_lstlast(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}
