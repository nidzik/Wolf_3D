/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:31:41 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/15 13:00:19 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <mlx.h>
# define WIN wlf.win
# define WINP wlf->win
# define MLX wlf.mlx
# define MLXP wlf->mlx

# define WIN_X 600
# define WIN_Y 400

typedef struct	s_wlf
{
	void		*mlx;
	void		*win;
	int			map_dim[2];
	int			**map;
}				t_wlf;
typedef struct	s_rep
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
}				t_rep;
typedef struct	s_cood
{
	double		x;
	double		y;
	double		z;
}				t_cood;

int expose_hook(t_wlf *wlf);
int key_hook(t_wlf *wlf);

int ft_init_window(t_wlf wlf);
void ft_init_env(t_wlf *wlf);

void ft_draw_map(t_wlf *wlf);
#endif
