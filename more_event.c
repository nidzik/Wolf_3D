/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 10:02:07 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/17 10:45:54 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf *up(t_wlf *w)
{
	if(w->map[(int)(w->p.posx + w->p.dirx * w->move_speed)][(int)w->p.posy] == 0)
		w->p.posx += w->p.dirx * w->move_speed;
	if(w->map[(int)w->p.posx][(int)(w->p.posy + w->p.diry * w->move_speed)] == 0)
		w->p.posy += w->p.diry * w->move_speed;
	printf("%f, %f",w->p.posx,w->p.posy);
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