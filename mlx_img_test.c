#include "cub3d.h"

t_xpm	*ft_xpm(t_data *data, char *name)
{
	t_img	*img;
	char	*res;
	t_xpm	*xp;
	xp = malloc(sizeof(t_xpm));
	xp->img = malloc(sizeof(t_img));
	img = xp->img;
	img->img_ptr = mlx_xpm_file_to_image(data->mlx, name, &xp->w, &xp->h);
	if (!img->img_ptr){
		fprintf(stderr, "Error!\n");exit(1);}
	xp->cpy_addr = malloc(sizeof(unsigned int *) * 2);
	xp->cpy_addr[0] = (unsigned int *)(mlx_get_data_addr(img->img_ptr, &img->bpp,&img->line_len, &img->endian));
	xp->cpy_addr[1] = NULL;
	return (xp);
}

void	ft_put_xpm_image(t_data *data, t_xpm *tableau)
{
	t_img *img = tableau->img;
	unsigned int	*addr = tableau->cpy_addr[0];

	printf("%X\n", tableau->w);
	int scale_factor = WIDTH / tableau->w;
	int w = tableau->w * scale_factor;
	int h = tableau->h * scale_factor;
	int o_w, o_h;

			printf("%X\n", addr[0]);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++){
			o_w = j / scale_factor;
			o_h = i / scale_factor;
			if (addr[o_h * tableau->w + o_w] != 0xFF000000)
				ft_put_pix( j, i, addr[o_h * tableau->w + o_w], data);
		}
	}
	// mlx_put_image_to_window(data->mlx, data->win, tableau->img->img_ptr, 0,0);
	printf("here\n");
}

void	ft_back(t_data *data)
{
	for (int i = 0 ; i < HEIGHT; i++)
		for(int j = 0; j < WIDTH; j++)
			ft_put_pix(i, j, 0x863E5A,data);
}

int	main(int ac, char **av)
{
	t_data *data;
	t_xpm	*absortion_img;
	t_xpm	*bad_omen_img;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "TSTS");
	//img init
	data->img = malloc(sizeof(t_img));
	data->img->img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr, &data->img->bpp,&data->img->line_len, &data->img->endian);
	//****
	printf("here\n");
	absortion_img = ft_xpm(data, "textures/example.xpm");
	bad_omen_img = ft_xpm(data, "textures/bad_omen.xpm");
	ft_back(data);
	ft_put_xpm_image(data, bad_omen_img);
	ft_put_img(data);
	mlx_loop(data->mlx);
}
