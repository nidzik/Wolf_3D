/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 11:47:38 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/23 16:07:29 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_tex2		init_text(t_tex2 t)
{
	t.x = 0;
	t.i = 0;
	t.y = 0;
	return (t);
}

t_wlf		*create_text(t_wlf *w)
{
	t_tex2 t;

	t = init_text(t);
	w->texture = (int **)malloc(sizeof(int*) * 7);
	while (t.i != 7)
	{
		w->texture[t.i] = (int *)malloc(sizeof(int) * ((64 * 64) + 1));
		t.i++;
	}
	w->texture[6] = NULL;
	t.i = 0;
	while (t.i < 6)
	{
		while (t.x <= TEXWIDTH)
		{
			t.y = 0;
			while (t.y <= TEXHEIGHT)
				t = ft_main_tex(t, w);
			t.x++;
		}
		t.x = 0;
		t.i++;
	}
	return (w);
}

t_tex2		ft_main_tex(t_tex2 t, t_wlf *w)
{
	t.c = 0;
	t.c += w->data2[t.i][(w->sizeline1 * t.y + t.x * 4)];
	t.c += w->data2[t.i][(w->sizeline1 * t.y + t.x * 4) + 1] << 8;
	t.c += w->data2[t.i][(w->sizeline1 * t.y + t.x * 4) + 2] << 16;
	w->texture[t.i][TEXWIDTH * t.y + t.x] = t.c;
	t.y++;
	return (t);
}

t_wlf		*create_text2(t_wlf *w, t_ray *r)
{
	double	wallx;

	if (r->side == 1)
		wallx = r->rayposx + ((r->mapy - r->rayposy + (1 - r->stepy) /
							2) / r->raydiry) * r->raydirx;
	else
		wallx = r->rayposy + ((r->mapx - r->rayposx + (1 - r->stepx) /
							2) / r->raydirx) * r->raydiry;
	wallx -= floor(wallx);
	w->texx = (wallx * (TEXWIDTH));
	if (r->side == 0 && r->raydirx > 0)
		w->texx = TEXWIDTH - w->texx - 1;
	if (r->side == 1 && r->raydiry < 0)
		w->texx = TEXWIDTH - w->texx - 1;
	return (w);
}
