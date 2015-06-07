/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 16:29:16 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/07 21:52:58 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int expose_hook(t_wlf *wlf)
{
	/* mlx_clear_window(MLXP, WINP); */
	ft_draw_map(wlf);
	return (0);
}

t_wlf *left(t_wlf *w)
{
	w->p.olddirx = w->p.dirx;
	w->p.dirx = w->p.dirx  * cos(w->speedrotate) - w->p.diry * sin(w->speedrotate);
	w->p.diry = w->p.olddirx  * sin(w->speedrotate) + w->p.diry  * cos(w->speedrotate);
	w->p.oldplanex = w->p.planex;
	w->p.planex = w->p.planex * cos(w->speedrotate) - w->p.planey *sin(w->speedrotate);
	w->p.planey = w->p.oldplanex  * sin(w->speedrotate) + w->p.planey  * cos(w->speedrotate) ;
	return (w);
}

t_wlf *right(t_wlf *w)
{
	w->p.olddirx = w->p.dirx;
	w->p.dirx = w->p.dirx  * cos(-w->speedrotate) - w->p.diry * sin(-w->speedrotate);
	w->p.diry = w->p.olddirx  * sin(-w->speedrotate) + w->p.diry  * cos(-w->speedrotate);
	w->p.oldplanex = w->p.planex;
	w->p.planex = w->p.planex * cos(-w->speedrotate) - w->p.planey *sin(-w->speedrotate);
	w->p.planey = w->p.oldplanex  * sin(-w->speedrotate) + w->p.planey  * cos(-w->speedrotate) ;

	return (w);
}

int key_hook(int keycode, t_wlf *wlf)
{
	printf("%d\n",keycode);
	if (keycode == 65307 || keycode == 53)
		exit(0);
	if (keycode == 65361 || keycode == 123)
		wlf = left(wlf);
	if (keycode == 65363 || keycode == 124)
		wlf = right(wlf);
	if (keycode == 126 || keycode == 65362)
		wlf = up(wlf);
	if (keycode == 125 || keycode == 65364)
		wlf = down(wlf);
	if (keycode == 116 || keycode == 65365)
		wlf->hwallvar += 0.05;
	if (keycode == 65366)
		wlf->hwallvar -= 0.05;
	if (keycode == 121 && wlf->hwallvar > -0.5)
		wlf->hwallvar -= 0.05;
	if (keycode == 82 || keycode == 65438)
		wlf->hwallvar = 0;
	wlf = tp(wlf);
	/* printf("sayhey");fflush(stdout); */
	/* usleep(1000); */
	expose_hook(wlf);
	return (0);
}

t_pos ft_right(t_pos pos, t_wlf *w)
{
	pos.olddirx = pos.dirx;
	pos.dirx = pos.dirx  * cos(-w->speedrotate) - pos.diry * sin(-w->speedrotate);
	pos.diry = pos.olddirx  * sin(-w->speedrotate) + pos.diry  * cos(-w->speedrotate);
	pos.oldplanex = pos.planex;
	pos.planex = pos.planex * cos(-w->speedrotate) - pos.planey *sin(-w->speedrotate);
	pos.planey = pos.oldplanex  * sin(-w->speedrotate) + pos.planey  * cos(-w->speedrotate) ;
	w->p.dirx = pos.dirx;
	w->p.diry = pos.diry;
	w->p.olddirx = pos.olddirx;
	w->p.planex = pos.planex;
	w->p.planey = pos.planey;
	w->p.oldplanex = pos.oldplanex;
	w->right = 0;
	return (pos);
}

t_pos ft_left(t_pos pos, t_wlf *w)
{
	pos.olddirx = pos.dirx;
	pos.dirx = pos.dirx  * cos(w->speedrotate) - pos.diry * sin(w->speedrotate);
	pos.diry = pos.olddirx  * sin(w->speedrotate) + pos.diry  * cos(w->speedrotate);
	pos.oldplanex = pos.planex;
	pos.planex = pos.planex * cos(w->speedrotate) - pos.planey *sin(w->speedrotate);
	pos.planey = pos.oldplanex  * sin(w->speedrotate) + pos.planey  * cos(w->speedrotate) ;
	w->p.dirx = pos.dirx;
	w->p.diry = pos.diry;
	w->p.olddirx = pos.olddirx;
	w->p.planex = pos.planex;
	w->p.planey = pos.planey;
	w->p.oldplanex = pos.oldplanex;
	w->left = 0;
	return (pos);
}
