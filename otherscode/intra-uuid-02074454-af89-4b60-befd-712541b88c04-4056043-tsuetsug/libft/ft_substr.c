/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:35:07 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:51:21 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (len <= 0 || start > ft_strlen(s) || *s == '\0')
	{
		substr = malloc(sizeof(char) * 1);
		if (!(substr))
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (!(substr))
		return (NULL);
	i = 0;
	while (len--)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
