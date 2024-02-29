/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:40:46 by rosman            #+#    #+#             */
/*   Updated: 2024/02/28 22:42:05 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bits_max(t_node *node)
{
	t_node	*current;
	int		max_number;
	int		max_bits;

	current = node;
	max_bits = 0;
	max_number = 0;
	while (current)
	{
		if (current->content > max_number)
		{
			max_number = current->content;
		}
		current = current->next;
	}
	while (max_number != 0)
	{
		max_bits++;
		max_number /= 2;
	}
	return (max_bits);
}

void	radix(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	stack_a_len;
	int	i;
	int	j;

	max_bits = bits_max(a->top);
	i = 0;
	while (i < max_bits)
	{
		stack_a_len = stack_len(a->top);
		j = 0;
		while (j < stack_a_len && is_sorted(a) == 0)
		{
			if ((a->top->index / (1 << i)) % 2 == 1)
				rotate_a(a);
			else if ((a->top->index / (1 << i)) % 2 == 0)
				push_b(a, b);
			j++;
		}
		while (b->top)
			push_a(b, a);
		i++;
	}
}
