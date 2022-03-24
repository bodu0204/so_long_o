/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:28:06 by mfujishi          #+#    #+#             */
/*   Updated: 2022/03/18 11:28:06 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static void	heap_make(int *array, int first, int len)
{
	int	parent;
	int	child;

	parent = first;
	child = (parent * 2) + 1;
	while (child < len)
	{
		if (child < len - 1 && array[child] < array[child + 1])
			child++;
		if (array[child] <= array[parent])
			break ;
		ft_swap(&array[parent], &array[child]);
		parent = child;
		child = (parent * 2) + 1;
	}
}

void	ft_heapsort(int *array, int len)
{
	int	first;

	first = (len - 2) / 2;
	while (first >= 0)
	{
		heap_make(array, first, len);
		first--;
	}
	while (len > 0)
	{
		len--;
		ft_swap(&array[0], &array[len]);
		heap_make(array, 0, len);
	}
}
