/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:39:31 by rosman            #+#    #+#             */
/*   Updated: 2024/02/29 20:55:39 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR 1
# define FREE 0 
# define EXIT 2 

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

void	sort_stacks(t_stack *a);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	cleanup(char **arv, int i);
void	check_arv(char **arv);
void	free_arv(char **arv, int i);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	start_stack(t_stack *stack);
int		stack_len(t_node *node);
int		is_sorted(t_stack *stack_a);
void	sort_three(t_stack *a);
void	swap_a(t_stack *stack);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_b, t_stack *stack_a);
void	rotate_a(t_stack *stack);
void	rotate_reverse_a(t_stack *stack);
t_node	*ft_lstlast(t_node *stack);
void	sort_four(t_stack *a, t_stack *b);
void	free_nodes(t_stack *stack, int i);
void	pop(t_stack *stack);// change it to out
void	sort_five(t_stack *a, t_stack *b);
t_node	*one_min(t_stack *stack);
void	radix(t_stack *a, t_stack *b);
int		ft_atoi(char *str, char **args, int *flag);
void	put_to_stack(char **arv, t_stack *stack);
void	push_to_stack(t_stack *stack, int content);

#endif