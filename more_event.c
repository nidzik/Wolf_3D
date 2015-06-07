/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 10:02:07 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/07 21:30:22 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf *up(t_wlf *w)
{
	if(w->map[(int)(w->p.posx + w->p.dirx * w->move_speed)][(int)w->p.posy] == 0)
		w->p.posx += w->p.dirx * w->move_speed;
	if(w->map[(int)w->p.posx][(int)(w->p.posy + w->p.diry * w->move_speed)] == 0)
		w->p.posy += w->p.diry * w->move_speed;
	/* printf("%f, %f",w->p.posx,w->p.posy); */
	return (w);
}

t_wlf *down(t_wlf *w)
{
	if(w->map[(int)(w->p.posx - w->p.dirx * w->move_speed)][(int)w->p.posy] == 0)
		w->p.posx -= w->p.dirx * w->move_speed;
	if(w->map[(int)w->p.posx][(int)(w->p.posy - w->p.diry * w->move_speed)] == 0)
		w->p.posy -= w->p.diry * w->move_speed;
	return (w);
}

t_wlf *tp(t_wlf *w)
{
	if (w->p.posx > 8 && w->p.posy < 2)
	{
		w->p.posx = 1;
		w->p.posy = 14;
	}
	return (w);
}
