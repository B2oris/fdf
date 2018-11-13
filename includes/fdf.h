/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 21:14:05 by beborch           #+#    #+#             */
/*   Updated: 2018/10/10 18:10:21 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE (4096)
# define WIN_X (2200)
# define WIN_Y (1200)

# include "libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_fdf
{
	char			buff[BUFF_SIZE + 1];
	char			*parse;
	int				file;
	int				ret;
	int				longu;
	int				haut;
	int				**tab;
	char			tmp[200];
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned char	*data_image;
	int				bpp;
	int				s_l;
	int				endian;
	int				zoom;
	int				zoom_tracing;
	int				pos_x;
	int				pos_y;
	int				**x;
	int				**y;
	int				iso;
	int				move_x;
	int				move_y;
	int				move_high_x;
	int				move_high_y;
	int				tracing_x;
	int				tracing_y;
	int				end_parse;
}					t_fdf;

typedef struct		s_bres
{
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				x;
	int				y;
	int				cumul;
}					t_bres;

int					set_tab(t_fdf *fdf);
void				set_struct(t_fdf *fdf);
void				get_longueur(t_fdf *fdf);
int					get_hauteur(t_fdf *fdf);
int					parsing(t_fdf *fdf);
int					get_parse(char *argu, t_fdf *fdf);
void				filling_white(t_fdf *fdf, int x, int y);
int					val_abs(int i);
void				fill_map(t_fdf *fdf, int xi, int xf, int yi, int yf);
void				fill_map_y(t_fdf *fdf, int i, int j);
void				fill_map_x(t_fdf *fdf, int i, int j);
void				put_color(t_fdf *fdf, int i, int j);
void				put_tracing(t_fdf *fdf);
int					get_number(t_fdf *fdf);
int					fill_tab(t_fdf *fdf);
void				show_tab(t_fdf *fdf);
int					parser(char *argu, t_fdf *fdf);
int					check_every_len(t_fdf *fdf);
void				car_to_iso(t_fdf *fdf);
void				set_trace(t_fdf *fdf);
void				get_position(t_fdf *fdf);
void				mapping(t_fdf *fdf, int i);
void				move_high(t_fdf *fdf, int key);
void				key_iso(t_fdf *fdf);
int					get_key(int key, t_fdf *fdf);
void				move(t_fdf *fdf, int key);
void				zoom(t_fdf *fdf, int key);
void				calcul_pos(t_fdf *fdf, int i, int j);
void				free_tab(t_fdf *fdf);
void				free_map(t_fdf *fdf);
void				wrong_map(t_fdf *fdf, int index);

#endif
