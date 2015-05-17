/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 16:29:16 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/17 16:27:42 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int expose_hook(t_wlf *wlf)
{
/* 	int lar = 30; */
/* 	int len = 30; */
	mlx_clear_window(MLXP, WINP);
	ft_draw_map(wlf);
/* 	wlf->text = mlx_xpm_file_to_image(MLXP, "textures/wolf3d-2017-nguye_1/carabine.xpm", &lar, &len); */

/*     mlx_put_image_to_window(MLXP, WINP, TEXT, 0,0); */
	return (0);
}
t_wlf *left(t_wlf *w)
{
	w->p.olddirx = w->p.dirx;
	w->p.dirx = w->p.dirx  * cos(0.3) - w->p.diry * sin(0.3);
	w->p.diry = w->p.olddirx  * sin(0.3) + w->p.diry  * cos(0.3);
	w->p.oldplanex = w->p.planex;
	w->p.planex = w->p.planex * cos(0.3) - w->p.planey *sin(0.3);
	w->p.planey = w->p.oldplanex  * sin(0.3) + w->p.planey  * cos(0.3) ;

	return (w);
}
t_wlf *right(t_wlf *w)
{
	w->p.olddirx = w->p.dirx;
	w->p.dirx = w->p.dirx  * cos(-0.3) - w->p.diry * sin(-0.3);
	w->p.diry = w->p.olddirx  * sin(-0.3) + w->p.diry  * cos(-0.3);
	w->p.oldplanex = w->p.planex;
	w->p.planex = w->p.planex * cos(-0.3) - w->p.planey *sin(-0.3);
	w->p.planey = w->p.oldplanex  * sin(-0.3) + w->p.planey  * cos(-0.3) ;

	return (w);
}

int key_hook(int keycode, t_wlf *wlf)
{
	printf("%d\n",keycode);

	if (keycode == 65307 || keycode == 53)
		exit(0);
	if (keycode == 65361 || keycode == 123)
	{
    printf("---%d \n",wlf->map[0][0]);fflush(stdout);
		wlf = left(wlf);
		wlf->right = 1;
	}
	if (keycode == 65363 || keycode == 124)
		wlf = right(wlf);
	if (keycode == 126)
		wlf = up(wlf);
	if (keycode == 125)
		wlf = down(wlf);
	wlf->left = 1;
	expose_hook(wlf);
	return (0);
}

t_pos ft_right(t_pos pos, t_wlf *w)
{
	pos.olddirx = pos.dirx;
	pos.dirx = pos.dirx  * cos(-0.3) - pos.diry * sin(-0.3);
	pos.diry = pos.olddirx  * sin(-0.3) + pos.diry  * cos(-0.3);
	pos.oldplanex = pos.planex;
	pos.planex = pos.planex * cos(-0.3) - pos.planey *sin(-0.3);
	pos.planey = pos.oldplanex  * sin(-0.3) + pos.planey  * cos(-0.3) ;
	w->p.dirx = pos.dirx;
	w->p.diry = pos.diry;
	w->p.olddirx = pos.olddirx;
	w->p.planex = pos.planex;
	w->p.planey = pos.planey;
	w->p.oldplanex = pos.oldplanex;
	w->right = 0;
	printf("1	w->p.dirx %f\n",	w->p.dirx);
	return (pos);
}

t_pos ft_left(t_pos pos, t_wlf *w)
{
	pos.olddirx = pos.dirx;
	pos.dirx = pos.dirx  * cos(0.3) - pos.diry * sin(0.3);
	pos.diry = pos.olddirx  * sin(0.3) + pos.diry  * cos(0.3);
	pos.oldplanex = pos.planex;
	pos.planex = pos.planex * cos(0.3) - pos.planey *sin(0.3);
	pos.planey = pos.oldplanex  * sin(0.3) + pos.planey  * cos(0.3) ;
	w->p.dirx = pos.dirx;
	w->p.diry = pos.diry;
	w->p.olddirx = pos.olddirx;
	w->p.planex = pos.planex;
	w->p.planey = pos.planey;
	w->p.oldplanex = pos.oldplanex;
	w->left = 0;
	return (pos);
}
