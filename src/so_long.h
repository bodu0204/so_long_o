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
	size_t	mc;
	size_t	item;
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_c;
	void	*img_e;
}	t_info;

#define BLOCKLEN 30
#define FILE_0 ""
#define FILE_1 ""
#define FILE_P ""
#define FILE_C ""
#define FILE_E ""

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
void	ft_bzero(void *s, size_t n);

#endif
