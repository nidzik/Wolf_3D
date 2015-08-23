/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:05:35 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/23 15:47:31 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf		ft_stockmap(t_wlf *wlf)
{
	char	*mapc;
	int		*mapi;

	mapc = "6, 6, 6, 6, 6, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1,\
6, 0, 0, 0, 6, 1, 0, 0, 2, 0, 0, 0, 2, 0, 0, 1,\
6, 0, 0, 0, 6, 1, 0, 0, 2, 0, 0, 0, 2, 0, 0, 1,\
6, 0, 0, 0, 6, 1, 0, 0, 0, 2, 0, 2, 0, 0, 0, 1,\
6, 0, 0, 0, 6, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1,\
6, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1,\
6, 0, 0, 0, 6, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 1,\
6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,\
6, 0, 0, 0, 6, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 1,\
6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1";
	ft_strlen(mapc);
	mapi = ft_char_to_int(mapc);
	wlf = creat_map(wlf, mapi);
	return (*wlf);
}

t_wlf		*creat_map(t_wlf *wlf, int *mapi)
{
	t_var var;

	wlf->map = (int **)malloc(sizeof(int *) * 11);
	var.i = 0;
	var.j = 0;
	var.k = 0;
	while (var.i < 10)
	{
		if (var.j == 0)
		{
			wlf->map[var.i] = (int *)malloc(sizeof(int) * 16);
			ft_bzero(wlf->map[var.i], 16);
		}
		wlf->map[var.i][var.j] = mapi[var.k];
		var.k++;
		var.j++;
		if (var.j == 16)
		{
			var.j = 0;
			var.i++;
		}
	}
	if (wlf->map == NULL)
		exit(1);
	return (wlf);
}

void		ft_init_env(t_wlf *wlf)
{
	wlf->hwallvar = 0;
	wlf->right = 0;
	wlf->left = 0;
	wlf->p.dirx = -1;
	wlf->p.diry = 0;
	wlf->p.planex = 0;
	wlf->p.planey = 0.66;
	wlf->p.posx = 5;
	wlf->p.posy = 3;
	wlf->speedrotate = 0.15;
	wlf->move_speed = 0.20;
	wlf->time = 0;
	wlf->oldtime = 0;
	ft_stockmap(wlf);
}

t_pos		ft_init_value(t_pos pos, t_wlf *w)
{
	pos.posx = w->p.posx;
	pos.posy = w->p.posy;
	pos.dirx = w->p.dirx;
	pos.diry = w->p.diry;
	pos.olddirx = w->p.olddirx;
	pos.planex = w->p.planex;
	pos.planey = w->p.planey;
	pos.oldplanex = w->p.oldplanex;
	pos.i = 0;
	pos.hwall = 1 + w->hwallvar;
	pos.color = 0;
	pos.color_sky = 0x3366cc;
	pos.color_floor = 0x336600;
	return (pos);
}

t_ray		ft_init_ray(t_ray r, t_pos p)
{
	r.hit = 0;
	r.camerax = 2 * p.i / (double)(WIN_X) - 1;
	r.rayposx = p.posx;
	r.rayposy = p.posy;
	r.raydirx = p.dirx + p.planex * r.camerax;
	r.raydiry = p.diry + p.planey * r.camerax;
	r.mapx = (int)(r.rayposx);
	r.mapy = (int)(r.rayposy);
	r.deltax = sqrt(1 + (r.raydiry * r.raydiry) / (r.raydirx * r.raydirx));
	r.deltay = sqrt(1 + (r.raydirx * r.raydirx) / (r.raydiry * r.raydiry));
	return (r);
}
