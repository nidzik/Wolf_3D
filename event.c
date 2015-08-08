/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 16:29:16 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/08 12:17:40 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			expose_hook(t_wlf *wlf)
{
	ft_draw_map(wlf);
	return (0);
}

t_wlf		*left(t_wlf *w)
{
	w->p.olddirx = w->p.dirx;
	w->p.dirx = w->p.dirx * cos(w->speedrotate) - w->p.diry *
		sin(w->speedrotate);
	w->p.diry = w->p.olddirx * sin(w->speedrotate) + w->p.diry *
		cos(w->speedrotate);
	w->p.oldplanex = w->p.planex;
	w->p.planex = w->p.planex * cos(w->speedrotate) - w->p.planey *
		sin(w->speedrotate);
	w->p.planey = w->p.oldplanex * sin(w->speedrotate) + w->p.planey *
		cos(w->speedrotate);
	return (w);
}

t_wlf		*right(t_wlf *w)
{
	w->p.olddirx = w->p.dirx;
	w->p.dirx = w->p.dirx * cos(-w->speedrotate) - w->p.diry *
							sin(-w->speedrotate);
	w->p.diry = w->p.olddirx * sin(-w->speedrotate) + w->p.diry *
							cos(-w->speedrotate);
	w->p.oldplanex = w->p.planex;
	w->p.planex = w->p.planex * cos(-w->speedrotate) - w->p.planey *
							sin(-w->speedrotate);
	w->p.planey = w->p.oldplanex * sin(-w->speedrotate) + w->p.planey *
							cos(-w->speedrotate);
	return (w);
}

int			key_hook(int keycode, t_wlf *wlf)
{
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
	if (keycode == 116  || keycode == 'u')
		wlf->hwallvar += 0.1;
	if ((keycode == 121  || keycode == 'j' )&& wlf->hwallvar > -0.5)
		wlf->hwallvar -= 0.1;
	if (keycode == 82)
		wlf->hwallvar = 0;
	wlf = tp(wlf);
	expose_hook(wlf);
	return (0);
}
