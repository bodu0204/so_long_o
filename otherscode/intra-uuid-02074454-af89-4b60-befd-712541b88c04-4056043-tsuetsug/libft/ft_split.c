/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:26:38 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:49:35 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_c(char const *s, char c)
{
	size_t	i;
	size_t	c_count;

	i = 0;
	c_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			c_count++;
		i++;
	}
	return (c_count);
}

void	*ft_sp_range(char **split_s, char const *s,
		t_split *s_ind, t_split *sp_ind)
{
	split_s[sp_ind->length] = ft_substr(s, s_ind->start, s_ind->length);
	sp_ind->length++;
	return (split_s);
}

void	*ft_split_by_char(char **split_s, char const *s, char c)
{
	size_t	i;
	t_split	s_ind;
	t_split	sp_ind;

	i = 0;
	sp_ind.length = 0;
	sp_ind.start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			s_ind.start = sp_ind.start;
			s_ind.length = (i - s_ind.start);
			if (i > sp_ind.start && !ft_sp_range(split_s, s, &s_ind, &sp_ind))
				return (NULL);
			sp_ind.start = i + 1;
		}
		i++;
	}
	s_ind.start = sp_ind.start;
	s_ind.length = (i - sp_ind.start);
	if (i > sp_ind.start && i > 0 && !ft_sp_range(split_s, s, &s_ind, &sp_ind))
		return (NULL);
	split_s[sp_ind.length] = 0;
	return (split_s);
}

char	**ft_split(char const *s, char c)
{
	char	**split_s;
	size_t	c_count;

	c_count = ft_count_c(s, c);
	if (c_count < 0)
		return (NULL);
	split_s = (char **)malloc(sizeof(s) * (c_count + 2));
	if (!split_s)
		return (NULL);
	if (!ft_split_by_char(split_s, s, c))
		return (NULL);
	return (split_s);
}
