/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 18:15:36 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/07 20:08:57 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
void   ft_draw_map(t_wlf *wlf)
{
	t_pos pos;
	t_ray r;
	/* int lar = 100; */
	/* int len = 100; */
	pos = ft_init_value(pos, wlf);
	/* printf("\n\n\n\n\n\n\n0"); */
	while(pos.i < WIN_X)
	{
		r = ft_init_ray(r, pos);
		r = ft_side_dist(&r);
		r = ft_find_wall(r, wlf);
		pos.lineh = abs((int)(pos.hwall * WIN_Y / r.walldist));
		pos.dstart = - pos.lineh / 2 + (pos.hwall * WIN_Y) / 2;
		pos.dend = pos.lineh / 2 + (pos.hwall * WIN_Y) / 2;
		if (pos.dstart < 0)
			pos.dstart = 0;
		if (pos.dend >= pos.hwall * WIN_Y)
			pos.dend = pos.hwall * WIN_Y - 1; 
		if (wlf->map[r.mapx][r.mapy] == 1)
		{
			if (r.raydirx < 0 && r.stepx < 0 && r.side == 0)
				pos.color = (pos.posy > 6) ? 0x885038 : 0xff9977;
/* 				pos.color = 0x885038;//0xff9977; */
			else
				pos.color = (pos.posy > 6) ? 0x668850 : 0xccff99;
/* 				pos.color = 0x668850;//0xccff99;; */
			
			
		}
		/* printf("%f %f      - > %f %f\n",pos.planex, pos.planey, pos.posx, pos.posy); */
		if (r.side == 1 && r.raydiry < 0 && r.stepy < 0)
			pos.color = (pos.posy > 6) ? 0x508816 : 0x99ff33;
/* 			pos.color = 0x508816;//0x99ff33; */
		else if (r.side == 1)
			pos.color = (pos.posy > 6) ? 0x446644 : 0x88cc88;
/* 			pos.color = 0x446644;//0x88cc88; */
		ft_draw_sky(wlf, pos);
/* 		pos.color/=2; */
		while (pos.dstart <= pos.dend)
			mlx_pixel_put(MLXP, WINP, pos.i, pos.dstart++, pos.color);
		ft_draw_floor(wlf, pos);
		pos.i++;	
	}

/* 	mlx_put_image_to_window(MLXP, WINP, TEXT, -180,-180); */
	return ;
}

t_ray	ft_side_dist(t_ray *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->rayposx - r->mapx) * r->deltax;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->rayposx) * r->deltax;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->rayposy - r->mapy) * r->deltay;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - r->rayposy) * r->deltay;
	}
	return (*r);
}

t_ray	ft_find_wall(t_ray r, t_wlf *wlf)
{
	r.side = 0;
	while (r.hit == 0)
	{
		if (r.sidedistx < r.sidedisty)
		{
			r.sidedistx += r.deltax;
			r.mapx += r.stepx;
			r.side = 0;
		}
		else 
		{
			r.sidedisty += r.deltay;
			r.mapy += r.stepy;
			r.side = 1;
		}
		if (wlf->map[r.mapx][r.mapy] > 0)
			r.hit = 1;
	}
	if (r.side == 0)
		r.walldist = fabs((r.mapx - r.rayposx + 
						   (1 - r.stepx) / 2) / r.raydirx);
	else
		r.walldist = fabs((r.mapy - r.rayposy + 
						   (1 - r.stepy) / 2) / r.raydiry);
	/* printf("- %d need 0  - %f - %f  %d  %d \n",r.side, r.raydiry, r.raydirx, r.stepx, r.stepy); */
	return(r);
}

t_wlf *ft_draw_sky(t_wlf *wlf, t_pos p)
{
	int i;
	int color_sky;
	int color_sky2;

	color_sky = 0x3366cc;
	color_sky2 = 0x3b2b00;
	(void)color_sky2; 
	i = 0;
	color_sky = (p.posy > 6) ? 0x3b2b00 : 0x3366cc;
	while (i < p.dstart)
	{
		mlx_pixel_put(MLXP, WINP, p.i, i++, color_sky);
	}
	return (wlf);
}

void ft_draw_floor(t_wlf *wlf, t_pos p)
{
	int i;
	int color_floor;
	int color_floor2;

	color_floor = 0x336600;
	color_floor2 = 0x3f4f00;
	(void)color_floor2;
	i = p.dend;
	color_floor = (p.posy > 6) ? 0x3f4f00 : 0x336600;
	while (i < WIN_Y)
	{
		mlx_pixel_put(MLXP, WINP, p.i, i++, color_floor);
	}
}
