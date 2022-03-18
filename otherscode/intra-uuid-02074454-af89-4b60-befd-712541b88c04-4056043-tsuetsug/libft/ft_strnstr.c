/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:46:41 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:14:04 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (len && haystack[i])
	{
		if (needle[j] == haystack[i])
		{
			while (needle[j] == haystack[i + j]
				&& (i + j < len) && haystack[i + j])
			{
				j++;
				if (!needle[j])
					return ((char *)(haystack + i));
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
