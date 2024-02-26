/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:53:38 by rosman            #+#    #+#             */
/*   Updated: 2024/02/26 22:42:17 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_stack(t_stack *stack)
{
	stack->top = NULL;
}

void	is_int(char **res)
{
	int	i;
	int	j;

	i = -1;
	while (res[++i])
	{
		j = 0;
		while (res[i][j] != '\0')
		{
			if (res[i][j] >= '0' && res[i][j] <= '9')
				j++;
			else if (res[i][j] == '-' || res[i][j] == '+')
			{
				if (j > 0 || (res[i][j + 1] == '\0'))
					cleanup(res, PRINT_ERROR);
				else
					j++;
			}
			else
				cleanup(res, PRINT_ERROR);
		}
	}
}

char	**return_numbers(char **arv)
{
	char	*join;
	char	**result;
	int		i;

	i = 0;
	check_arv(arv);
	join = ft_strdup("");
	if (join == NULL)
		return (free(join), NULL);
	while (arv[++i])
	{
		join = ft_strjoin(join, arv[i]);
		join = ft_strjoin(join, " ");
	}
	result = ft_split(join, ' ');
	if (result == NULL)
		return (free(result), NULL);
	free(join);
	is_int(result);
	return (result);
}

void	cleanup(char **arv, int i)
{
	if (i == JUST_EXIT)
	{
		ft_printf("ERROR!\n");
		exit(1);
	}
	free_arv(arv, i);
	exit(1);
}

void	free_arv(char **arv, int i)
{
	int	counter;

	counter = 0;
	if (i == 1)
		ft_printf("ERROR!\n");
	if (arv)
	{
		while (arv[i])
		{
			free(arv[i]);
			i++;
		}
		free(arv);
	}
}

void	pop(t_stack *stack)
{
	t_node	*temp;

	if (stack->top == NULL)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
}

void	free_nodes(t_stack *stack, int i)
{
	if (i == 1)
		ft_printf("ERROR!\n");
	while (stack->top != NULL)
		pop(stack);
}

void	check_arv(char **arv)
{
	int	i;
	int	j;

	i = 0;
	while (arv[i])
	{
		if (*arv[i] == '\0')
			cleanup(arv, JUST_EXIT);
		else
		{
			if (*arv)
			{
				j = 0;
				while (arv[i][j] == ' ')
				{
					if (arv[i][j] == '\0')
						cleanup(arv, JUST_EXIT);
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
	ft_printf("the number : %s", numbers);
	return (0);
}
