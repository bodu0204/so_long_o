/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:14:44 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:55:16 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	while (in(s1[start], set) == 0)
		start++;
	while (in(s1[len - 1], set) == 0)
		len--;
	if (len == 0)
		return (ft_substr(s1, ft_strlen(s1), ft_strlen(s1)));
	return (ft_substr(s1, start, len - start));
}
