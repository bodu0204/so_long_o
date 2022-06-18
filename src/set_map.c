#include"so_long.h"

void	set_map(t_info	*i)
{
	size_t	j;
	size_t	c;
	size_t	e;

	j = 0;
	c = 0;
	e = 0;
	while (i->map_c[j] == '1')
		j++;
	if (i->map_c[j] != '\n')
		file_error(i->map_c);
	i->map_w = j;
	i->map_h = 1;
	c = j;
	j++;
	while (i->map_c[j])
		set_block(i, &j, &c, &e);
	if (j % (i->map_w + 1) || !(i->mc) || !(i->item) || !e)
		file_error(i->map_c);
	i->map_c[c + 1] = '\0';
	while (c % i->map_w)
	{
		if (i->map_c[c] != '1')
			file_error(i->map_c);
		c--;
	}
	if (i->map_c[c] != '1')
		file_error(i->map_c);
	return ;
}

void	set_block(t_info i, size_t	*j, size_t	*c, size_t	*e)
{
	if ((!(*j % (i->map_w + 1)) && i->map_c[*j] != '1')\
		|| (!((*j + 2) % (i->map_w + 1)) && i->map_c[*j] != '1')\
		|| (!((*j + 1) % (i->map_w + 1)) && i->map_c[*j] != '\n')\
		|| (i->mc && i->map_c[*j] == 'P'))
		file_error(i->map_c);
	if (i->map_c[*j] == '0' || i->map_c[*j] == '1' || i->map_c[*j] == 'C' || i->map_c[*j] == 'E')
	{
		if (i->map_c[*j] == 'C')
			i->item++;
		else if (i->map_c[*j] == 'E')
			*e++;
		i->map_c[*c] = i->map_c[*j];
	}
	else if (i->map_c[*j] == 'P')
	{
		i->mc = *c;
		i->map_c[*c] = '0';
	}
	else if (!(i->map_c[*j] == '\n' && !((*j + 1) % (i->map_w + 1))))
		file_error(i->map_c);
	if ((*j + 1) % (i->map_w + 1))
		*c++;
	else
		i->map_h++;
	*j++;
}
