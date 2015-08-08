/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:31:41 by nidzik            #+#    #+#             */
/*   Updated: 2015/08/08 13:10:32 by nidzik           ###   ########.fr       */
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

# define WIN	wlf.win
# define WINP	wlf->win
# define MLX	wlf.mlx
# define MLXP	wlf->mlx
# define TEXT	wlf->text
# define IMG	wlf.img
# define IMGP	 wlf->img
# define texWidth 64
# define texHeight 64
# define WIN_X	800
# define WIN_Y	500

typedef	struct	s_pos
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
	double		hwall;
	int			color;
}				t_pos;

typedef	struct	s_wlf
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			bpp1;
	int			sizeline;
	int			sizeline1;
	int			endian;
	int			endian1;
	char		*data;
	char		*data1;
	char		*data2;
	void		*text;
	void		*textu;
	int			map_dim[2];
	int			**map;
	double		right;
	double		left;
	double		time;
	double		oldtime;
	double		frametime;
	t_pos		p;
	double		hwallvar;
	double		speedrotate;
	double		move_speed;
	int		*texture;
  int texX;
}				t_wlf;

typedef	struct	s_ray
{
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		planex;
	double		planey;
	double		sidedistx;
	double		sidedisty;
	double		deltax;
	double		deltay;
	double		walldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
}				t_ray;

typedef	struct	s_cood
{
	double		x;
	double		y;
	double		z;
}				t_cood;

typedef struct	s_var
{
	int			i;
	int			j;
	int			k;
}				t_var;

int				expose_hook(t_wlf *wlf);
int				key_hook(int keycode, t_wlf *wlf);

t_wlf			ft_init_window(t_wlf wlf);
void			ft_init_env(t_wlf *wlf);
t_ray			ft_init_ray(t_ray r, t_pos p);
t_pos			ft_init_value(t_pos pos, t_wlf *w);
t_wlf			ft_stockmap(t_wlf *wlf);

void			ft_draw_map(t_wlf *wlf);
t_ray			ft_side_dist(t_ray *r);
t_ray			ft_find_wall(t_ray r, t_wlf *wlf);
t_pos			ft_left(t_pos pos, t_wlf *w);
t_wlf			*up(t_wlf *w);
t_wlf			*down(t_wlf *w);
t_wlf			*ft_draw_sky(t_wlf *wlf, t_pos p);
void			ft_draw_floor(t_wlf *wlf, t_pos p);
int				ft_key_hook(int keycode);
t_wlf			*tp(t_wlf *w);
int				color(t_wlf *wlf, t_pos pos, t_ray r);
t_wlf			*creat_map(t_wlf *wlf, int *mapi);
int				*ft_char_to_int(char *str);
t_wlf			*create_text(t_wlf *w);
t_wlf			*create_text2(t_wlf *w, t_ray *r);

#endif
