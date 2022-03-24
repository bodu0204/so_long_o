/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:27:54 by mfujishi          #+#    #+#             */
/*   Updated: 2022/03/18 11:27:54 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	negative;
	long	ret;

	i = 0;
	negative = -1;
	ret = 0;
	while (*nptr && ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' '))
		nptr++;
	if (*nptr == '-')
		negative = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		ret = ret * 10 - (nptr[i++] - '0');
		if (((ret <= -922337203685477580 && 7 < nptr[i] - '0') || 19 < i) && \
			negative == -1)
			return ((int) -1);
		if (((ret <= -922337203685477580 && 8 < nptr[i] - '0') || 19 < i) && \
			negative == 1)
			return ((int)0);
	}
	return ((int)ret * negative);
}
