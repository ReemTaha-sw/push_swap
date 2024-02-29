/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:31:46 by rosman            #+#    #+#             */
/*   Updated: 2024/02/29 20:59:05 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->top;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

t_node	*get_min(t_stack *stack)
{
	t_node	*curr;
	t_node	*temp;
	int		min;

	curr = stack->top;
	min = 0;
	temp = NULL;
	while (curr)
	{
		if (curr->index == -1 && (min == 0
				|| temp->content > curr->content))
		{
			temp = curr;
			min = 1;
		}
		curr = curr->next;
	}
	return (temp);
}

t_node	*put_index_min(t_stack *stack)
{
	t_node	*current;
	int		index;

	index = 0;
	current = get_min(stack);
	while (current)
	{
		current->index = index++;
		current = get_min(stack);
	}
	return (current);
}

void	sort_stacks(t_stack *a)
{
	t_stack	b;

	start_stack(&b);
	put_index_min(a);
	if (is_sorted(a) == 0)
	{
		if (stack_len(a->top) == 3)
			sort_three(a);
		else if (stack_len(a->top) == 4)
			sort_four(a, &b); 
		else if (stack_len(a->top) == 5)
			sort_five(a, &b); 
		else 
			radix(a, &b);
	}
	free_nodes(&b, 0);
}
