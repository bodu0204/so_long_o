/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:02:50 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:53:40 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy_s1;
	int		s1_len;
	int		i;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	cpy_s1 = malloc(sizeof(char) * s1_len + 1);
	if (cpy_s1 != NULL)
	{
		i = 0;
		while (s1[i])
		{
			cpy_s1[i] = s1[i];
			i++;
		}
		cpy_s1[i] = '\0';
		return (cpy_s1);
	}
	return (NULL);
}
