/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:55:35 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 15:42:08 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calcul_pos(t_fdf *fdf, int i, int j)
{
	if (fdf->tab[j][i] != 0)
		fdf->x[j][i] = fdf->pos_x - (fdf->tab[j][i] * fdf->zoom)
			+ fdf->move_x + fdf->move_high_x;
	else
		fdf->x[j][i] = fdf->pos_x + fdf->move_x;
	if (fdf->tab[j][i] != 0)
		fdf->y[j][i] = fdf->pos_y - (fdf->tab[j][i] * fdf->zoom)
			+ fdf->move_y + fdf->move_high_y;
	else
		fdf->y[j][i] = fdf->pos_y + fdf->move_y;
}

int		val_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	free_tab(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->haut)
	{
		free(fdf->tab[i]);
		free(fdf->x[i]);
		free(fdf->y[i]);
		i++;
	}
	free(fdf->parse);
	free(fdf->x);
	free(fdf->y);
	free(fdf->tab);
	exit(0);
}
