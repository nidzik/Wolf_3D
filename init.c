/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:05:35 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/07 21:33:17 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf ft_stockmap(t_wlf *wlf)
{

	int i = 0;
	int j = 0;
	int k = 0;
	int len_map[] = {16, 10};
	int map[] = { 
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		 };


	wlf->map = (int **)malloc(sizeof(int *)* 11);
	while (i < 10)
	{
		if (j == 0)
			wlf->map[i] = (int *)malloc(sizeof (int) *16);
		wlf->map[i][j] = map[k];
		k++;
		j++;
		if (j == 16)
		{
			j = 0;
			i++;
		}
	}
	wlf->map_dim[0] = len_map[0];
	wlf->map_dim[1] = len_map[1];
	if (wlf->map == NULL)
		exit(1);
	return (*wlf);
}

void ft_init_env(t_wlf *wlf)
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
	wlf->speedrotate = 0.09;
	wlf->move_speed = 0.1;
	wlf->time = 0;
	wlf->oldtime = 0;
	ft_stockmap(wlf);
}

t_pos	ft_init_value(t_pos pos, t_wlf *w)
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
	return (pos);
}

t_ray	ft_init_ray(t_ray r, t_pos p)
{
	r.hit = 0;
	r.camerax = 2 * p.i / (double)(WIN_X) -1;
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
