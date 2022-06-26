#include"so_long.h"

void	get_map(t_info *i, char *name)
{
	read_map(i, 0, name, 0);
	convert_map(i);
	check_map(i);
	set_mob(i);
	return ;
}

void	read_map(t_info	*i, int	fd, char	*name, size_t	s)
{
	char	buf[BUFSIZ];
	ssize_t	j;

	if (name)
	{
		fd = open(name, O_RDONLY);
		if (fd < 0)
			error_exit("Unreadable file\n");
	}
	j = read(fd, buf, BUFSIZ);
	if (j < 0)
		error_exit("Read error\n");
	if (j == 0)
	{
		close(fd);
		i->map_c = malloc(s + j + 1);
		if (!i->map_c)
			error_exit("malloc errror\n");
		i->map_c[s + j] = '\0';
	}
	else
		read_map(i, fd, NULL, s + j);
	ft_memcpy(i->map_c + s, buf, j);
	return ;
}

void	convert_map(t_info	*i)
{
	size_t	j;
	size_t	c;
	size_t	l;

	j = 0;
	c = 0;
	while (i->map_c[j])
	{
		l = 0;
		while (i->map_c[j] && i->map_c[j] != '\n')
		{
			i->map_c[c] = i->map_c[j];
			j++;
			c++;
			l++;
		}
		if (l == j)
			i->map_w = l;
		if (i->map_w != l || i->map_c[j] != '\n')
			file_error(i->map_c, "line errror\n");
		i->map_h++;
		j++;
	}
	i->map_c[c] = '\0';
	return ;
}

void	check_map(t_info	*i)
{
	size_t	m[5];

	ft_bzero(m, sizeof(size_t) * 5);
	while (i->map_c[m[0]])
	{
		if (is_map_elem(i->map_c[m[0]], m[0], i->map_w, i->map_h))
			file_error(i->map_c, "charractor error\n");
		if (i->map_c[m[0]] == 'E')
			m[1]++;
		else if (i->map_c[m[0]] == 'C')
			i->item++;
		else if (i->map_c[m[0]] == 'P')
			m[2]++;
		else if (i->map_c[m[0]] == 'M')
			m[3]++;
		else if (i->map_c[m[0]] == 'F')
			m[4]++;
		m[0]++;
	}
	if (!m[1] || !i->item || !m[2] || m[2] > 1 || m[3] > 1 || m[4] > 1)
		file_error(i->map_c, "charractor sum error\n");
	return ;
}
