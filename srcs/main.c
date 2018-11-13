/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 21:12:01 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 15:42:23 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			set_windows(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_X - 400, WIN_Y, "fdf");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_X, WIN_Y);
	fdf->data_image = (unsigned char *)mlx_get_data_addr(fdf->img_ptr,
			&fdf->bpp, &fdf->s_l, &fdf->endian);
	fdf->iso = 0;
	mlx_key_hook(fdf->win_ptr, get_key, fdf);
	mapping(fdf, 0);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}

int			error(void)
{
	ft_putstr("error\n");
	return (-1);
}

void		free_map(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->haut)
	{
		free(fdf->x[i]);
		free(fdf->y[i]);
		i++;
	}
	free(fdf->x);
	free(fdf->y);
}

int			main(int argc, char *argv[])
{
	t_fdf	fdf;

	set_struct(&fdf);
	if (argc != 2)
	{
		ft_putstr("Usage :\n ./fdf <map>\n");
		exit(0);
	}
	if (parser(argv[1], &fdf) == -1)
		return (error());
	show_tab(&fdf);
	set_windows(&fdf);
	return (0);
}
