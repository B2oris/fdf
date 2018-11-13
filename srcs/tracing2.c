/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 01:41:01 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 15:42:03 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	car_to_iso(t_fdf *fdf)
{
	int i;
	int j;
	int tmp_x;

	j = 0;
	while (j < fdf->haut)
	{
		i = 0;
		while (i < fdf->longu)
		{
			tmp_x = fdf->x[j][i];
			fdf->x[j][i] = (fdf->x[j][i] - fdf->y[j][i]) + 900;
			fdf->y[j][i] = ((tmp_x + fdf->y[j][i]) / 2) + 200;
			i++;
		}
		j++;
	}
}

void	set_trace(t_fdf *fdf)
{
	if (fdf->longu > 20 || fdf->haut > 20)
	{
		fdf->tracing_x = 5 + fdf->zoom_tracing;
		fdf->tracing_y = 5 + fdf->zoom_tracing;
	}
	else
	{
		fdf->tracing_x = 100 + fdf->zoom_tracing;
		fdf->tracing_y = 100 + fdf->zoom_tracing;
	}
	fdf->pos_x = (WIN_X / 2) - fdf->longu * fdf->tracing_x / 2;
	fdf->pos_y = (WIN_Y / 2) - fdf->haut * fdf->tracing_y / 2;
}

void	set_x_y(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((fdf->x = (int**)ft_memalloc(sizeof(int*) * fdf->haut)) == NULL)
		free_tab(fdf);
	if ((fdf->y = (int**)ft_memalloc(sizeof(int*) * fdf->haut)) == NULL)
		free_tab(fdf);
	while (i < fdf->haut)
	{
		if ((fdf->x[i] = (int*)ft_memalloc(sizeof(int) * fdf->longu)) == NULL)
			free_tab(fdf);
		if ((fdf->y[i] = (int*)ft_memalloc(sizeof(int) * fdf->longu)) == NULL)
			free_tab(fdf);
		i++;
	}
}

void	get_position(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	set_x_y(fdf);
	while (j < fdf->haut)
	{
		fdf->pos_x = 200;
		while (i < fdf->longu)
		{
			calcul_pos(fdf, i, j);
			fdf->pos_x += fdf->tracing_x;
			i++;
		}
		fdf->pos_y += fdf->tracing_y;
		i = 0;
		j++;
	}
}

void	put_tracing(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < fdf->haut)
	{
		i = 0;
		while (i < fdf->longu)
		{
			if (i + 1 < fdf->longu)
				fill_map_x(fdf, i, j);
			if (i < fdf->longu && j < fdf->haut - 1)
				fill_map_y(fdf, i, j);
			i++;
		}
		j++;
	}
}
