/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:27:55 by mfujishi          #+#    #+#             */
/*   Updated: 2022/03/18 11:27:55 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	first;
	size_t	len;

	if (s1 == NULL)
		return (0);
	else if (set == NULL)
		return ((char *)s1);
	len = ft_strlen(s1);
	first = 0;
	while (s1[first] != '\0' && ft_strchr(set, s1[first]) != 0)
		first++;
	while (len > 0 && ft_strchr(set, s1[len]) != 0)
		len--;
	ret = ft_substr(s1, first, (len - first) + 1);
	if (!(ret))
		return (0);
	return (ret);
}
