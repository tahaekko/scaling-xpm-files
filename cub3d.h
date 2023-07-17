#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define HEIGHT 600
#define WIDTH 600
#define SCALE_FACTOR 2


typedef struct s_img{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_img;

typedef struct s_xpm{
	int		w;
	int		h;
	unsigned int	**cpy_addr;
	t_img	*img;
}t_xpm;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_xpm	*xp;
}t_data;


void	ft_put_pix(int x, int y, int color,t_data *data);
void	ft_put_img(t_data *data);
int	color_code(int r ,int g ,int b);
