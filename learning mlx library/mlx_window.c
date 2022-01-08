#include <mlx.h>

int main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 600, "new mlx window!");
	mlx_loop(mlx);
}
