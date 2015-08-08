/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 10:02:07 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/14 15:01:00 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf		*up(t_wlf *w)
{
	if (w->map[(int)(w->p.posx + w->p.dirx *
		w->move_speed)][(int)w->p.posy] == 0)
		w->p.posx += w->p.dirx * w->move_speed;
	if (w->map[(int)w->p.posx][(int)(w->p.posy + w->p.diry
		* w->move_speed)] == 0)
		w->p.posy += w->p.diry * w->move_speed;
	return (w);
}

t_wlf		*down(t_wlf *w)
{
	if (w->map[(int)(w->p.posx - w->p.dirx *
		w->move_speed)][(int)w->p.posy] == 0)
		w->p.posx -= w->p.dirx * w->move_speed;
	if (w->map[(int)w->p.posx][(int)(w->p.posy - w->p.diry *
		w->move_speed)] == 0)
		w->p.posy -= w->p.diry * w->move_speed;
	return (w);
}

t_wlf		*tp(t_wlf *w)
{
	if (w->p.posx > 8 && w->p.posy < 2)
	{
		w->p.posx = 2;
		w->p.posy = 13;
	}
	return (w);
}

int			*ft_char_to_int(char *str)
{
	int		*map;
	int		i;
	int		*save;

	map = (int *)malloc(sizeof(int) * 160);
	save = map;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1')
			i++;
		else
		{
			map[0] = 1;
			*map = str[i] - 48;
			i++;
			map++;
		}
	}
	return (save);
}

int			color(t_wlf *wlf, t_pos pos, t_ray r)
{
	if (wlf->map[r.mapx][r.mapy] == 1)
	{
		if (r.raydirx < 0 && r.stepx < 0 && r.side == 0)
			pos.color = (pos.posy > 6) ? 0x885038 : 0xff9977;
		else
			pos.color = (pos.posy > 6) ? 0x668850 : 0xccff99;
	}
	if (r.side == 1 && r.raydiry < 0 && r.stepy < 0)
		pos.color = (pos.posy > 6) ? 0x508816 : 0x99ff33;
	else if (r.side == 1)
		pos.color = (pos.posy > 6) ? 0x446644 : 0x88cc88;
	ft_draw_sky(wlf, pos);
	return (pos.color);
}
