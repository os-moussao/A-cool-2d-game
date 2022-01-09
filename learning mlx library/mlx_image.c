#include <stdio.h>
#include <mlx.h>

typedef struct s_img
{
	void	*img;
	int		h;
	int		w;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

int main()
{
	t_mlx mlx;
	t_img img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "heyy!");
	img.img = mlx_xpm_file_to_image(mlx.mlx, "./res/wall_e.xpm", &img.w, &img.h);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 50, 50);
	if (img.img)
		printf("height = %d	width = %d\n", img.h, img.w);
	else
		printf("NULL\n");
	mlx_loop(mlx.mlx);
};
