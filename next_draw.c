/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 19:30:07 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/22 20:09:56 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_draw_floor(t_wlf *wlf, t_pos pos)
{
	wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 0] = pos.color_floor;
	wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 1] = pos.color_floor >> 8;
	wlf->data[pos.y * wlf->sizeline + 4 * pos.i + 2] =
		pos.color_floor >> 16;
}
