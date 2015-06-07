/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:31:41 by nidzik            #+#    #+#             */
/*   Updated: 2015/06/06 13:31:12 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <mlx.h>
# include <time.h>
# include <sys/time.h>

# define WIN wlf.win
# define WINP wlf->win
# define MLX wlf.mlx
# define MLXP wlf->mlx
# define TEXT wlf->text
# define IMG wlf.img
# define IMGP wlf->img

# define WIN_X 600
# define WIN_Y 400

# define R r->
# define W wlf->

typedef struct	s_pos
{
	double		posx;
	double		posy;
	double		dirx;
	double		olddirx;
	double		diry;
	double		olddiry;
	double		planex;
	double		oldplanex;
	double		planey;
	double		oldplaney;
	int			i;
    int			dstart;
    int			dend;
	int			lineh;
	int			hwall;
	int			color;
}				t_pos;

typedef struct	s_wlf
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			sizeline;
	int			endian;
	char		*data;
	char		*data1;
	void		*text;
	int			map_dim[2];
	int			**map;
	double		right;
	double		left;
	double		time;
	double		oldtime;
	double		frametime;
	t_pos		p;
	double		speedrotate;
	double		move_speed;
}				t_wlf;


typedef struct	s_ray
{
	double camerax;
	double rayposx;
	double rayposy;
	double raydirx;
	double raydiry;
	int		mapx;
	int		mapy;
	double	planex;
	double	planey;
	double	sidedistx;
	double	sidedisty;
	double	deltax;
	double	deltay;
	double	walldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}				t_ray;

typedef struct	s_cood
{
	double		x;
	double		y;
	double		z;
}				t_cood;

int expose_hook(t_wlf *wlf);
int key_hook(int keycode, t_wlf *wlf);

t_wlf ft_init_window(t_wlf wlf);
void ft_init_env(t_wlf *wlf);
t_ray   ft_init_ray(t_ray r, t_pos p);
t_pos   ft_init_value(t_pos pos, t_wlf *w);
t_wlf	ft_stockmap(t_wlf *wlf);

void	ft_draw_map(t_wlf *wlf);
t_ray   ft_side_dist(t_ray *r);
t_ray   ft_find_wall(t_ray r, t_wlf *wlf);
t_pos	ft_left(t_pos pos, t_wlf *w);
t_wlf	*up(t_wlf *w);
t_wlf	*down(t_wlf *w);
t_wlf *ft_draw_sky(t_wlf *wlf, t_pos p);
void ft_draw_floor(t_wlf *wlf, t_pos p);
int     ft_key_hook(int keycode);

#endif
