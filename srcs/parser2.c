/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:46:48 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 16:57:52 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		set_tab(t_fdf *fdf)
{
	int i;

	i = 0;
	if ((fdf->tab = (int **)malloc(sizeof(int *) * (fdf->haut))) == NULL)
		return (-1);
	i = 0;
	while (i < fdf->haut)
	{
		if ((fdf->tab[i] = (int *)malloc(sizeof(int) * (fdf->longu))) == NULL)
			return (-1);
		i++;
	}
	return (0);
}

void	get_longueur(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->parse[i] != '\n' && fdf->parse[i] != '\0')
	{
		if (fdf->parse[i] != ' ')
		{
			fdf->longu++;
			while (fdf->parse[i] != ' ' && fdf->parse[i] != '\n'
					&& fdf->parse[i] != '\0')
				i++;
		}
		if (fdf->parse[i] == '\n' || fdf->parse[i] == '\0')
			break ;
		i++;
	}
}

int		get_hauteur(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->parse[i] != '\0')
	{
		if (fdf->parse[i] == '\n')
			fdf->haut++;
		i++;
	}
	if (fdf->parse[i] == '\0' && fdf->parse[i - 1] != '\n')
		fdf->haut++;
	if (fdf->haut == 0)
		fdf->haut = 1;
	return (0);
}

int		check_every_len(t_fdf *fdf)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (fdf->parse[i] != '\0')
	{
		if (fdf->parse[i] != ' ' && fdf->parse[i] != '\n')
			len++;
		if (fdf->parse[i] == '\n')
		{
			if (fdf->longu > len)
			{
				ft_putstr("map incorrect.\n");
				return (-1);
			}
			len = 0;
		}
		i++;
	}
	return (0);
}

int		parsing(t_fdf *fdf)
{
	get_longueur(fdf);
	get_hauteur(fdf);
	if (check_every_len(fdf) == -1)
		return (-1);
	return (0);
}
