/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:46:48 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/23 15:51:03 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf		ft_init_window(t_wlf wlf)
{
	int		lar;
	int		len;
	t_tex	tex;

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
	mlx_put_image_to_window(MLX, WIN, wlf.text, -100, -80);
	wlf = texture_di_ouf(wlf, tex, len, lar);
	mlx_loop(wlf.mlx);
	return (wlf);
}

t_wlf		texture_di_ouf(t_wlf wlf, t_tex tex, int len, int lar)
{
	wlf.data2 = (char **)malloc(sizeof(char *) * 7);
	wlf.textu = mlx_xpm_file_to_image(MLX, "pics/redbrick.xpm", &lar, &len);
	wlf.data2[0] = mlx_get_data_addr(wlf.textu, &wlf.bpp1, &wlf.sizeline1,
									&wlf.endian1);
	wlf.textu = mlx_xpm_file_to_image(MLX, "pics/eagle.xpm", &lar, &len);
	wlf.data2[1] = mlx_get_data_addr(wlf.textu, &tex.bpp, &tex.sl, &tex.endian);
	wlf.textu = mlx_xpm_file_to_image(MLX, "pics/barrel.xpm", &lar, &len);
	wlf.data2[2] = mlx_get_data_addr(wlf.textu, &tex.bpp, &tex.sl, &tex.endian);
	wlf.textu = mlx_xpm_file_to_image(MLX, "pics/mossy.xpm", &lar, &len);
	wlf.data2[3] = mlx_get_data_addr(wlf.textu, &tex.bpp, &tex.sl,
									&tex.endian);
	wlf.textu = mlx_xpm_file_to_image(MLX, "pics/pillar.xpm", &lar, &len);
	wlf.data2[4] = mlx_get_data_addr(wlf.textu, &tex.bpp, &tex.sl,
									&tex.endian);
	wlf.textu = mlx_xpm_file_to_image(MLX, "pics/wood.xpm", &lar,
									&len);
	wlf.data2[5] = mlx_get_data_addr(wlf.textu, &tex.bpp, &tex.sl,
										&tex.endian);
	wlf.textu = mlx_xpm_file_to_image(MLX, "pics/redbrick.xpm", &lar,
								&len);
	wlf.data2[6] = NULL;
	return (wlf);
}
