/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:59:45 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:26:14 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dst;
	char	*ptr_src;

	if (dst == src || len == 0)
		return (dst);
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (ptr_dst < ptr_src)
	{
		while (len--)
			*ptr_dst++ = *ptr_src++;
	}
	else
	{
		ptr_dst = ptr_dst + len - 1;
		ptr_src = ptr_src + len - 1;
		while (len--)
		{
			*ptr_dst = *ptr_src;
			ptr_dst--;
			ptr_src--;
		}
	}
	return (dst);
}
