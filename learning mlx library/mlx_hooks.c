#include <mlx.h>
#include <stdio.h>

#define LC 1
#define RC 2
#define MC 3
#define SU 4
#define SD 5

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

int	key_hook(int keycode, t_mlx *mlx)
{
	printf("hello from key_hook %d!\n", keycode);
	return 0;
}

int mouse_hook(int key, t_mlx *mlx)
{
	printf("hello from mouse_hook %d\n", key);
	return 0;
}

int main()
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 600, "new window!");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
}
