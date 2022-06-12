#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"

typedef struct s_info
{
	void	*mlx;
	void	*win;
	size_t	map_w;
	size_t	map_h;
	char	*map_c;
}	t_info;

#define BLOCKLEN 32

enum
{
	NO_KEY,
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	ESC_KEY
};

void	error_exit(char *msg);
int set_gkey(int key, void *p);
int rm_gkey(int	key, void	*p);

size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif