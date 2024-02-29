/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:20:12 by rosman            #+#    #+#             */
/*   Updated: 2024/02/28 22:21:04 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (is_sorted(a) == 0)
	{
		if (a->top->index < a->top->next->index 
			&& a->top->next->index > a->top->next->next->index)
		{
			rotate_reverse_a(a);
			swap_a(a);
		}
		else if (a->top->index > a->top->next->index 
			&& a->top->next->index < a->top->next->next->index)
			swap_a(a);
		else if (a->top->index < a->top->next->index 
			&& a->top->next->index > a->top->next->next->index)
			rotate_reverse_a(a);
		else if (a->top->index > a->top->next->index 
			&& a->top->next->index < a->top->next->next->index)
			rotate_a(a);
		else if (a->top->index > a->top->next->index 
			&& a->top->next->index > a->top->next->next->index)
		{
			swap_a(a);
			rotate_reverse_a(a);
		}
	}
}

