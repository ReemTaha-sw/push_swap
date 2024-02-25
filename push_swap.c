/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:53:38 by rosman            #+#    #+#             */
/*   Updated: 2024/02/24 22:46:31 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	creat_stack(t_stack *stack)
{
	stack->top = NULL;
}

char	**return_numbers(char **arv)
{
	char	*join;
	char	**result;
	int		i;

	i = 0;
	check_arv(arv);
}

void	cleanup(char **arv, int i)
{
	if (i = JUST_EXIT)
	{
		write(2, "ERROR!\n", 7);
		exit(1);
	}
	
}

void	check_arv(char **arv)
{
	int	i;
	int	j;

	i = 0;
	while (arv[i])
	{
		if (*arv[i] == '\0')
			do_this(arv, JUST_EXIT);
		else
		{
			if (*arv)
			{
				j = 0;
				while (arv[i][j] == ' ')
				{
					if (arv[i][j] == '\0')
						do_this(arv, JUST_EXIT);
					j++;
				}
			}
		}
		i++;
	}
}

int    main(int arc, char **arv)
{
	char	**numbers;
	t_stack	stack_a;

	start_stack(&stack_a);
	if (arc > 2)
	{
		numbers = return_numbers(arv);
	}
	ft_printf("hi , arc = %i and arv = %s", arc, arv[1]);
	return 0;
}