/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:47 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:27:22 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	total;

	total = size * count;
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (total--)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
