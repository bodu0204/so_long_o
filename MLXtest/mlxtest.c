#include"mlx.h"
#include"debug.h"

int a(void *b)
{
	return (0);
}


int main (void){
	void *mlx;
	void *win;

	mlx = NULL;
	mlx = NULL;

	mlx = mlx_init();
TESTp("mlx", mlx) //STOP
	win = mlx_new_window(mlx, 1000, 1000, "testing");
TESTp("win", win) //STOP
	mlx_key_hook(win, NULL, NULL);
	//mlx_pixel_put(mlx, win, 0, 0, 0xffffff);
TEST
	mlx_loop(mlx);
TEST STOP
	mlx_destroy_window(mlx, win);
	return (0);
}
