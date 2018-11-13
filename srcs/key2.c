/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 21:12:01 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 15:42:31 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	modif_taille(t_fdf *fdf, int key)
{
	if (key == 18 && fdf->zoom_tracing < 50)
		fdf->zoom_tracing += 1;
	if (key == 19)
		fdf->zoom_tracing -= 1;
	mapping(fdf, 1);
}

void	move_iso(t_fdf *fdf, int key)
{
	if (key == 125)
	{
		fdf->move_x += 10;
		fdf->move_y += 10;
		mapping(fdf, 1);
	}
	if (key == 126)
	{
		fdf->move_x -= 10;
		fdf->move_y -= 10;
		mapping(fdf, 1);
	}
	if (key == 124)
	{
		fdf->move_x += 10;
		fdf->move_y -= 10;
		mapping(fdf, 1);
	}
	if (key == 123)
	{
		fdf->move_x -= 10;
		fdf->move_y += 10;
		mapping(fdf, 1);
	}
}

int		get_key(int key, t_fdf *fdf)
{
	if (key == 18 || key == 19)
		modif_taille(fdf, key);
	if (key == 69 || key == 78)
		zoom(fdf, key);
	if (key == 12)
		key_iso(fdf);
	if (key >= 123 || key <= 126)
	{
		if (fdf->iso == 0)
			move(fdf, key);
		else
			move_iso(fdf, key);
	}
	if (key == 13 || key == 0 || key == 1 || key == 2)
		move_high(fdf, key);
	if (key == 53)
		free_tab(fdf);
	return (0);
}
