/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:11:52 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:23:23 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*space;
	int		i;
	int		x;

	if (!s1 || !s2)
		return (NULL);
	space = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!space)
		return (NULL);
	i = 0;
	x = 0;
	while (s1[i] != '\0')
		space[x++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		space[x++] = s2[i++];
	space[x] = '\0';
	return (&space[0]);
}
