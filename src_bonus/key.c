#include"so_long.h"

int	set_gkey(int	key, void	*p)
{
	t_info	*i;

	i = p;
	if (key == 0 || key == 123)
		i->newkey = LEFT;
	else if (key == 1 || key == 125)
		i->newkey = BACK;
	else if (key == 2 || key == 124)
		i->newkey = RIGHT;
	else if (key == 13 || key == 126)
		i->newkey = FRONT;
	else if (key == 53)
		i->newkey = ESC_KEY;
	else
		i->newkey = NO_KEY;
	return (0);
}

int	rm_gkey(int	key, void	*p)
{
	t_info	*i;

	i = p;
	(void)key;
	i->newkey = NO_KEY;
	return (0);
}