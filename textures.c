/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 11:47:38 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/08 16:01:10 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wlf *create_text(t_wlf *w)
{

  int x;
  int y;

  x = 0;
  y = 0;
  w->texture = malloc(sizeof(int) * (64 * 64) + 1);
  while (x <= texWidth)
    {
      y = 0;
      while (y <= texHeight)
	{
/* 	  int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight); */
	  //	  int xycolor = y * 128 / texHeight + x * 128 / texWidth + 500 ;

		int c = 0;
			c += w->data2[(w->sizeline1 * y + x*4)] ; 
		c += w->data2[(w->sizeline1 * y + x *4) +1] << 8 ; 
		c += w->data2[(w->sizeline1 * y + x *4)+2] << 16; 
		w->texture[texWidth * y + x] = c;//w->data2[texWidth * y + x]; 
//256 * xorcolor;
//xycolor + 256 * xycolor + 65536 * xycolor;
	  y++;
/* 	  printf("%d\n",w->texture[texWidth * y + x]);fflush(stdout); */
	}
      x++;
    }
return (w);
}
t_wlf *create_text2(t_wlf *w, t_ray *r)
{
  //  int texnum = w->map[r->mapx][r->mapy];
  double wallX; //where exactly the wall was hit
  if (r->side == 1)
	  wallX = r->rayposx + ((r->mapy - r->rayposy + (1 - r->stepy) / 2) / r->raydiry) * r->raydirx;
  else
	  wallX = r->rayposy + ((r->mapx - r->rayposx + (1 - r->stepx) / 2) / r->raydirx) * r->raydiry;
  wallX -= floor((wallX));

  //x coordinate on the texture
  w->texX =  (wallX * (texWidth));
  if(r->side == 0 && r->raydirx > 0) w->texX = texWidth - w->texX - 1;
  if(r->side == 1 && r->raydiry < 0) w->texX = texWidth - w->texX - 1;
return (w);
}
