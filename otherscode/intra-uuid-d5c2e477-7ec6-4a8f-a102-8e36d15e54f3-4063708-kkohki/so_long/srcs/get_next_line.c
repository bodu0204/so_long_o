/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:27:02 by kkohki            #+#    #+#             */
/*   Updated: 2022/03/08 04:20:25 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_getline(int fd, char *save)
{
	char	*buff;
	ssize_t	read_fd;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_fd = 1;
	while (!ft_strchr_gnl(save, '\n') && read_fd != 0)
	{
		read_fd = read(fd, buff, BUFFER_SIZE);
		if (read_fd == READ_ERROR)
		{
			free(buff);
			return (NULL);
		}
		buff[read_fd] = '\0';
		save = ft_strjoin_gnl(save, buff);
	}
	free(buff);
	return (save);
}

static char	*ft_line(char *save)
{
	size_t	i;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	return (ft_substr_gnl(save, 0, i + 1));
}

static char	*ft_save(char *save)
{
	size_t	i;
	char	*str;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
		{
			str = ft_substr_gnl(save, i + 1, ft_strlen_gnl(save));
			free(save);
			return (str);
		}
		i++;
	}
	free (save);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || INT_MAX <= BUFFER_SIZE)
		return (NULL);
	save = ft_getline(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_save(save);
	return (line);
}
