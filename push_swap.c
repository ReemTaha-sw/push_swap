/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:53:38 by rosman            #+#    #+#             */
/*   Updated: 2024/02/27 22:35:29 by rosman           ###   ########.fr       */
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
					cleanup(res, ERROR);
				else
					j++;
			}
			else
				cleanup(res, ERROR);
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
		return (free(join), NULL);
	free(join);
	is_int(result);
	return (result);
}

void	cleanup(char **arv, int i)
{
	if (i == EXIT)
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
			cleanup(arv, EXIT);
		else
		{
			if (*arv)
			{
				j = 0;
				while (arv[i][j] == ' ')
				{
					j++;
					if (arv[i][j] == '\0')
						cleanup(arv, EXIT);
				}
			}
		}
		i++;
	}
}

void	put_stack(char **arv, t_stack *stack)
{
	int	index;
	int	numbers;
	int	flag;

	index = 0;
	flag = 0;
	while (arv[index])
		index++;
	while (index > 0)
	{
		numbers = ft_atoi(arv[--index], arv, &flag);
		if (flag == 1)
		{
			free_nodes(stack, FREE);
			exit(1);
		}
		push_to_stack(stack, numbers);
	}
}

void	is_duplcates(t_stack * stack_a)
{
	t_node	*curr;
	t_node	*temp;

	curr = stack_a->top;
	if (!stack_a)
		return ;
	while (curr->next)
	{
		temp = curr->next;
		while (temp)
		{
			if (curr->content == temp->content)
			{
				free_nodes(stack_a, ERROR);
				exit(1);
			}
			temp = temp->next;
		}
		curr = curr->next;
	}
}

int    main(int arc, char **arv)
{
	char	**numbers;
	t_stack	stack_a;

	numbers = NULL;//delete it later
	start_stack(&stack_a);
	if (arc >= 2)
	{
		numbers = return_numbers(arv);
		put_stack(arv, &stack_a);
		free_arv(arv, FREE);
		is_duplcates(&stack_a);
		sort_stacks(&stack_a);
		free_nodes(&stack_a, FREE);
	}
	// ft_printf("hi , arc = %i and arv = %s", arc, arv[1]);
	// ft_printf("the number : %i", numbers);
	return (0);
}
