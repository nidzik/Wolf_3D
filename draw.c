/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 18:15:36 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/06 13:46:17 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
t_wlf *mlx_put_pixel_to_image(t_wlf *wlf, int x, int y, int color)
{
	int px;

	px = y * wlf->sizeline + x * (wlf->bpp / 8);
	/* wlf->data[0] = 'f'; */
	printf("izi %d  \n",px );fflush(stdout);
	wlf->data1[px+1] = color;
	wlf->data1[px + 2] = color >> 8;
	wlf->data1[px + 3] = color >> 16;
	return (wlf);
}
void   ft_draw_map(t_wlf *wlf)
{
	t_pos pos;
	t_ray r;
	static int i = 0;
	/* int lar = 100; */
	/* int len = 100; */
	if (i == 0)
	{
	wlf->data = mlx_get_data_addr(IMGP, &wlf->bpp, &wlf->sizeline, &wlf->endian);
    wlf->data1 = (char *)malloc(sizeof(char) * (wlf->bpp * wlf->sizeline + 4 ));
	i = 1;
	}
	pos = ft_init_value(pos, wlf);
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
		/* if (pos.i % 30 == 0) */
			/* sleep(1); */
		/* printf("pos.dstart     %d pos.dend %d      %d %d \n",pos.dstart, pos.dend, pos.i,(int)r.walldist);fflush(stdout); */
		
		if (wlf->map[r.mapx][r.mapy] == 1)
			pos.color = 0xff9955;
		else
			pos.color = 0x5599ff;
		if (r.side == 1)
			pos.color = pos.color / 2;
		ft_draw_sky(wlf, pos);
		while (pos.dstart <= pos.dend)
			mlx_put_pixel_to_image(MLXP, pos.i, pos.dstart++, pos.color);
/* mlx_pixel_put(MLXP, WINP, pos.i, pos.dstart++, pos.color); */
		ft_draw_floor(wlf, pos);
		pos.i++;	
	}
/* 	wlf->text = mlx_new_image(MLXP, 50,  50); */

/* 	wlf->text = mlx_xpm_file_to_image(MLXP, "textures/wolf3d-2017-nguye_1/carabine.xpm", &lar, &len); */
	/* sleep(1); */
	/* mlx_put_image_to_window(MLXP, WINP, TEXT, -180,-180); */
    wlf->frametime = (wlf->time - wlf->oldtime ) / 1000.0;
    /* if (wlf->right == 1) */
    /*     pos = ft_right(pos, wlf); */
    /* else if (wlf->left == 1) */
    /*     pos = ft_left(pos, wlf); */

    printf("fps : %f\n",  1.0 / wlf->frametime);
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
	/* printf("%d   %d \n",(int)r.walldist, r.side); */
	return(r);
}

t_wlf *ft_draw_sky(t_wlf *wlf, t_pos p)
{
	int i;
	int color_sky;

	color_sky = 0x5555ee;
	i = 0;
	while (i < p.dstart)
	{
		wlf = mlx_put_pixel_to_image(MLXP, p.i, i++, color_sky);
		/* mlx_pixel_put(MLXP, WINP, p.i, i++, color_sky); */
	}
	return (wlf);
}

void ft_draw_floor(t_wlf *wlf, t_pos p)
{
	int i;
	int color_floor;

	color_floor = 0x20ee20,
	i = p.dend;
	while (i < WIN_Y)
	{
		mlx_put_pixel_to_image(MLXP, p.i, i++, color_floor);
		/* mlx_pixel_put(MLXP, WINP, p.i, i++, color_floor); */
	}
}
