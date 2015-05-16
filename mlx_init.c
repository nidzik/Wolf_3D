/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:46:48 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/16 00:31:43 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf ft_init_window(t_wlf wlf)
{
	MLX = mlx_init();
	wlf.win = mlx_new_window(MLX, WIN_X, WIN_Y, "wlf");
	mlx_expose_hook(WIN, expose_hook, &wlf);
	mlx_key_hook(WIN, key_hook, &wlf);
	ft_putendl("init win");
    /* printf("---%d \n",wlf.map[0][0]); */
//	ft_draw_map(&wlf);
	mlx_loop(wlf.mlx);

	return (wlf);
}
