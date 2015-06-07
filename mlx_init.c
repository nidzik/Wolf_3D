/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:46:48 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/06 13:22:55 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
int key_stop(t_wlf *wlf)
{
	mlx_do_key_autorepeatoff(MLXP);
	return 0;
}
t_wlf ft_init_window(t_wlf wlf)
{
	/* int lar = 10; */
	/* int len = 10; */
	MLX = mlx_init();
	wlf.win = mlx_new_window(MLX, WIN_X, WIN_Y, "wlf");
	IMG = mlx_new_image(MLX, WIN_X, WIN_Y);
		printf("press");fflush(stdout);
	/* wlf.data = mlx_get_data_addr(IMG, &wlf.bpp, &wlf.sizeline, &wlf.endian); */
	/* wlf.data1 = (char *)malloc(sizeof(char) * (wlf.bpp * wlf.sizeline + 4 )); */
	/* bzero(wlf.data1, wlf.bpp * wlf.sizeline + 4); */
	/* wlf.data[0] = 49; */
		printf("press");fflush(stdout);


//		mlx_do_key_autorepeaton(MLX);
		mlx_hook(WIN, 2, (1L << 0), key_hook, &wlf);
		/* mlx_hook(WIN, 3, (1L << 1), key_stop, &wlf); */

		/* sleep(1); */

	
	/* sleep(1); */

	mlx_expose_hook(WIN, expose_hook, &wlf);
	//mlx_key_hook(WIN, key_hook, &wlf);
	ft_putendl("init win");
    printf("---%d \n",wlf.map[0][0]);
//	ft_draw_map(&wlf);
	/* wlf.text = mlx_xpm_file_to_image(MLX, "textures/wolf3d-2017-nguye_1/carabine.xpm", &lar, &len); good one */
	mlx_loop(wlf.mlx);
	
	return (wlf);
}

/* int		ft_key_hook(int keycode) */
/* { */
/*     printf("ft : %d\n",keycode); */

/*     if (keycode == 65307 || keycode == 53) */
/*         exit(0); */
/*     if (keycode == 65361 || keycode == 123) */
/*     { */
/* 		printf("1"); */
/*         /\* wlf = left(wlf); *\/ */
/*         /\* wlf->right = 1; *\/ */
/*     } */
/*     if (keycode == 65363 || keycode == 124) */
/* 		printf("2"); */
/*         /\* wlf = right(wlf); *\/ */
/*     if (keycode == 126 || keycode == 65362) */
/* 		printf("3"); */
/*         /\* wlf = up(wlf); *\/ */
/*     if (keycode == 125 || keycode == 65364) */
/* 		printf("4"); */
/*         /\* wlf = down(wlf); *\/ */
/*     /\* wlf->left = 1; *\/ */
/*     /\* expose_hook(wlf); *\/ */
/* 	usleep(1.2); */
/* 	return (0); */
/* } */
