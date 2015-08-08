/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:46:48 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/08 15:59:57 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf	ft_init_window(t_wlf wlf)
{
	int lar;
	int len;

	len = 100;
	lar = 100;
	MLX = mlx_init();
	wlf.win = mlx_new_window(MLX, WIN_X, WIN_Y, "wlf");
	IMG = mlx_new_image(MLX, WIN_X, WIN_Y);
	wlf.data = mlx_get_data_addr(IMG, &wlf.bpp, &wlf.sizeline, &wlf.endian);
	mlx_hook(WIN, 2, (1L << 0), key_hook, &wlf);
	mlx_expose_hook(WIN, expose_hook, &wlf);
	wlf.text = mlx_xpm_file_to_image(MLX,
				"assault.xpm", &lar, &len);
	wlf.textu = mlx_xpm_file_to_image(MLX, "pics/redbrick.xpm", &lar,  &len);
	wlf.data2 = mlx_get_data_addr(wlf.textu, &wlf.bpp1, &wlf.sizeline1, &wlf.endian1);
	mlx_loop(wlf.mlx);
	return (wlf);
}
