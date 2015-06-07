/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:46:48 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/07 21:27:37 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf ft_init_window(t_wlf wlf)
{
	MLX = mlx_init();
	wlf.win = mlx_new_window(MLX, WIN_X, WIN_Y, "wlf");
	IMG = mlx_new_image(MLX, WIN_X, WIN_Y);
	mlx_hook(WIN, 2, (1L << 0), key_hook, &wlf);

/* 	mlx_key_hook(WIN, key_hook, &wlf); */
/* 	mlx_do_key_autorepeaton(MLX); */
/* 	mlx_hook(WIN, 3, (1L << 1), key_stop, &wlf); */
	mlx_expose_hook(WIN, expose_hook, &wlf);
	//mlx_key_hook(WIN, key_hook, &wlf);
//	ft_draw_map(&wlf);
/* 	wlf.text = mlx_xpm_file_to_image(MLX, "textures/wolf3d-2017-nguye_1/carabine.xpm", &lar, &len); */
	/* usleep(5000); */
	mlx_loop(wlf.mlx);
	
	return (wlf);
}
