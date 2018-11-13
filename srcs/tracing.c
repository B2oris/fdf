/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 01:41:01 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 15:41:56 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	filling_white(t_fdf *fdf, int x, int y)
{
	int i;

	i = (y * WIN_X + x) * 4;
	fdf->data_image[i] = 200;
	fdf->data_image[i + 1] = 200;
	fdf->data_image[i + 2] = 200;
}

void	bresenham(t_fdf *fdf, t_bres *bres)
{
	int cumul;
	int i;

	i = 1;
	cumul = bres->dx / 2;
	while (i <= bres->dx)
	{
		bres->x += bres->xinc;
		cumul += bres->dy;
		if (cumul >= bres->dx)
		{
			cumul -= bres->dx;
			bres->y += bres->yinc;
		}
		if (bres->x > 0 && bres->y > 0 && bres->y < 1200 && bres->x < 2200)
			filling_white(fdf, bres->x, bres->y);
		i++;
	}
}

void	bresenham_bis(t_fdf *fdf, t_bres *bres)
{
	int cumul;
	int i;

	i = 1;
	cumul = bres->dy / 2;
	while (i <= bres->dy)
	{
		bres->y += bres->yinc;
		cumul += bres->dx;
		if (cumul >= bres->dy)
		{
			cumul -= bres->dy;
			bres->x += bres->xinc;
		}
		if (bres->x > 0 && bres->y > 0 && bres->y < 1200 && bres->x < 2200)
			filling_white(fdf, bres->x, bres->y);
		i++;
	}
}

void	fill_map_x(t_fdf *fdf, int i, int j)
{
	t_bres bres;

	bres.x = fdf->x[j][i];
	bres.y = fdf->y[j][i];
	bres.dx = fdf->x[j][i + 1] - fdf->x[j][i];
	bres.dy = fdf->y[j][i + 1] - fdf->y[j][i];
	bres.xinc = (bres.dx > 0) ? 1 : -1;
	bres.yinc = (bres.dy > 0) ? 1 : -1;
	bres.dx = val_abs(bres.dx);
	bres.dy = val_abs(bres.dy);
	if (bres.dx > bres.dy)
		bresenham(fdf, &bres);
	else
		bresenham_bis(fdf, &bres);
}

void	fill_map_y(t_fdf *fdf, int i, int j)
{
	t_bres bres;

	bres.x = fdf->x[j][i];
	bres.y = fdf->y[j][i];
	bres.dx = fdf->x[j + 1][i] - fdf->x[j][i];
	bres.dy = fdf->y[j + 1][i] - fdf->y[j][i];
	bres.xinc = (bres.dx > 0) ? 1 : -1;
	bres.yinc = (bres.dy > 0) ? 1 : -1;
	bres.dx = val_abs(bres.dx);
	bres.dy = val_abs(bres.dy);
	if (bres.dx > bres.dy)
		bresenham(fdf, &bres);
	else
		bresenham_bis(fdf, &bres);
}
