/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:37:36 by rosman            #+#    #+#             */
/*   Updated: 2024/02/28 22:39:45 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	if (a->top == one_min(a))
		push_b(a, b);
	else if (a->top->next == one_min(a))
		swap_a(a);
	else if (a->top->next->next == one_min(a))
	{
		rotate_reverse_a(a);
		rotate_reverse_a(a);
		rotate_reverse_a(a);
	}
	else if (a->top->next->next->next == one_min(a))
	{
		rotate_reverse_a(a);
		rotate_reverse_a(a);
	}
	else if (a->top->next->next->next->next == one_min(a))
		rotate_reverse_a(a);
	push_b(a, b);
	sort_four(a, b);
	push_a(b, a);
}
