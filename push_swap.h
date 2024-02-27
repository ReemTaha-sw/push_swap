/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:39:31 by rosman            #+#    #+#             */
/*   Updated: 2024/02/27 22:33:11 by rosman           ###   ########.fr       */
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

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	cleanup(char **arv, int i);
void	check_arv(char **arv);
void	free_arv(char **arv, int i);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif