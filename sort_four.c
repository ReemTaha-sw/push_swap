/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:29:43 by rosman            #+#    #+#             */
/*   Updated: 2024/02/28 22:38:39 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*one_min(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		got_min;

	current = stack->top;
	got_min = 0;
	temp = NULL;
	while (current)
	{
		if (got_min == 0 || temp->content > current->content)
		{
			temp = current;
			got_min = 1;
		}
		current = current->next;
	}
	return (temp);
}

void	sort_four(t_stack *a, t_stack *b)
{
	if (a->top == one_min(a))
		push_b(a, b);
	else if (a->top->next == one_min(a))
	{
		swap_a(a);
		push_b(a, b);
	}
	else if (a->top->next->next == one_min(a))
	{
		rotate_reverse_a(a);
		rotate_reverse_a(a);
		push_b(a, b);
	}
	else if (a->top->next->next->next == one_min(a))
	{
		rotate_reverse_a(a);
		push_b(a, b); 
	}
	sort_three(a);
	push_a(b, a);
}
