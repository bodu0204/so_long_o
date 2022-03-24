/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:23:03 by mfujishi          #+#    #+#             */
/*   Updated: 2022/03/18 11:23:05 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		ft_strcmp(const char *s1, const char *s2);
int		ft_isint(char *num);
void	ft_heapsort(int *array, int len);
void	ft_swap(int *a, int *b);
char	*ft_strndup(const char *s, size_t n);
size_t	ft_strcount(const char *s, char c);

#endif
