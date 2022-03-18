/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:50:42 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:18:00 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (len--)
	{
		*ptr_dst = *ptr_src;
		if (*ptr_src == (unsigned char)c)
		{
			ptr_dst++;
			return (ptr_dst);
		}
		ptr_dst++;
		ptr_src++;
	}
	return (NULL);
}
