#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define LC 1
#define RC 2
#define MC 3
#define SU 4
#define SD 5

#define ESC 53

#define WIDTH 1000
#define HEIGHT 500

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

int	close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return 0;
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == ESC)
		close(mlx);
	printf("key pressed: %d\n", key);
	return 0;
}

int mouse_press(int key, t_mlx *mlx)
{
	printf("botton pressed: %d\n", key);
	return 0;
}

int	mouse_pos(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		printf("(%d, %d)\n", x, y);
	return 0;
}

int main()
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "new window!");
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 4, 0, mouse_press, &mlx);
	mlx_hook(mlx.win, 6, 0, mouse_pos, &mlx);
	mlx_loop(mlx.mlx);
}
