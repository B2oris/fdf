/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 21:12:01 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 15:42:37 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mapping(t_fdf *fdf, int i)
{
	if (i == 1)
		free_map(fdf);
	set_trace(fdf);
	get_position(fdf);
	if (fdf->iso == 1)
		car_to_iso(fdf);
	ft_memset(fdf->data_image, 0, WIN_X * WIN_Y * 4);
	put_tracing(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void	zoom(t_fdf *fdf, int key)
{
	if (key == 69 && fdf->zoom < 50)
		fdf->zoom += 2;
	if (key == 78 && fdf->zoom > -50)
		fdf->zoom -= 2;
	mapping(fdf, 1);
}

void	key_iso(t_fdf *fdf)
{
	if (fdf->iso == 0)
		fdf->iso = 1;
	else
		fdf->iso = 0;
	mapping(fdf, 1);
}

void	move(t_fdf *fdf, int key)
{
	if (key == 124)
	{
		fdf->move_x += 10;
		fdf->move_y += 0;
		mapping(fdf, 1);
	}
	if (key == 123)
	{
		fdf->move_x -= 10;
		fdf->move_y -= 0;
		mapping(fdf, 1);
	}
	if (key == 126)
	{
		fdf->move_x -= 0;
		fdf->move_y -= 10;
		mapping(fdf, 1);
	}
	if (key == 125)
	{
		fdf->move_x -= 0;
		fdf->move_y += 10;
		mapping(fdf, 1);
	}
}

void	move_high(t_fdf *fdf, int key)
{
	if (key == 2)
	{
		fdf->move_high_x += 10;
		mapping(fdf, 1);
	}
	if (key == 0)
	{
		fdf->move_high_x -= 10;
		mapping(fdf, 1);
	}
	if (key == 13)
	{
		fdf->move_high_y -= 10;
		mapping(fdf, 1);
	}
	if (key == 1)
	{
		fdf->move_high_y += 10;
		mapping(fdf, 1);
	}
}
