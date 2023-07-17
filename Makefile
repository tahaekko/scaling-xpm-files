all :
	cc  libx_tools.c   mlx_img_test.c -lmlx -framework OpenGL -framework AppKit -o lol
clean :
	rm -rf lol
