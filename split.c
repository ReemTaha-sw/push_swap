/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:25:39 by rosman            #+#    #+#             */
/*   Updated: 2024/02/27 21:38:57 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strings_count(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			word_count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**substr;
	int		word_count;

	if (s == NULL)
		return (0);
	word_count = strings_count(s, c);
	substr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		substr[j++] = ft_substr(s, start, i - start);
	}
	substr[j] = NULL;
	return (substr);
}

int	ft_atoi(char *str, char **args, int *flag)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' )
	{
		res = res * 10 + *str - '0';
		if (res > 2147483647 || res < -2147483648)
		{
			free_args(args, 1);
			*flag = 1;
			return (0);
		}
		str++;
	}
	return (res * sign);
}
