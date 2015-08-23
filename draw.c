/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 18:15:36 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/23 16:07:10 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_draw_map(t_wlf *wlf)
{
	t_pos	pos;
	t_ray	r;

	pos = ft_init_value(pos, wlf);
	wlf = create_text(wlf);
	while (pos.i < WIN_X)
	{
		r = ft_init_ray(r, pos);
		r = ft_side_dist(&r);
		r = ft_find_wall(r, wlf);
		pos.lineh = abs((int)(pos.hwall * WIN_Y / r.walldist));
		pos.dstart = -pos.lineh / 2 + (pos.hwall * WIN_Y) / 2;
		pos.dend = pos.lineh / 2 + (pos.hwall * WIN_Y) / 2;
		if (pos.dstart < 0)
			pos.dstart = 0;
		if (pos.dend >= pos.hwall * WIN_Y)
			pos.dend = pos.hwall * WIN_Y - 1;
		wlf = create_text2(wlf, &r);
		pos.y = 0;
		while (pos.y < WIN_Y)
			pos = ft_draw2(wlf, pos, r);
		pos.i++;
	}
	print_map(wlf);
}

t_pos		ft_draw2(t_wlf *wlf, t_pos pos, t_ray r)
{
	if (pos.y < pos.dstart)
	{
		wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 0] = pos.color_sky;
		wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 1] = pos.color_sky >> 8;
		wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 2] = pos.color_sky >> 16;
	}
	if (pos.y >= pos.dstart && pos.y <= pos.dend)
	{
		pos.d = pos.y * 256 - (pos.hwall * WIN_Y) * 128 + pos.lineh * 128;
		pos.texy = ((pos.d * TEXHEIGHT) / pos.lineh) / 256;
		wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 0] = wlf->texture[wlf->map
			[r.mapx][r.mapy] - 1][TEXHEIGHT * pos.texy + wlf->texx];
		wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 1] = wlf->texture[wlf->map
			[r.mapx][r.mapy] - 1][TEXHEIGHT * pos.texy + wlf->texx] >> 8;
		wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 2] = wlf->texture[wlf->map
			[r.mapx][r.mapy] - 1][TEXHEIGHT * pos.texy + wlf->texx] >> 16;
		pos.dstart++;
	}
	else if (pos.y > pos.dend)
	{
		ft_draw_floor(wlf, pos);
	}
	pos.y++;
	return (pos);
}

void		print_map(t_wlf *wlf)
{
	mlx_put_image_to_window(MLXP, WINP, IMGP, 0, 0);
	mlx_put_image_to_window(MLXP, WINP, TEXT, -100, -80);
}

t_ray		ft_side_dist(t_ray *r)
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

t_ray		ft_find_wall(t_ray r, t_wlf *wlf)
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
	return (r);
}
