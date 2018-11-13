/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:46:48 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 16:04:51 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_number(t_fdf *fdf)
{
	static int	index = 0;
	int			j;
	char		tmp[200];

	j = 0;
	while (fdf->parse[index] != '\0')
	{
		while (fdf->parse[index] != ' ' && fdf->parse[index] != '\0'
				&& fdf->parse[index] >= '0' && fdf->parse[index] <= '9')
		{
			tmp[j] = fdf->parse[index];
			index++;
			j++;
			if (fdf->parse[index] == ' ' || fdf->parse[index] == '\0' ||
					fdf->parse[index] == '\n')
			{
				tmp[j] = '\0';
				return (ft_atoi(tmp));
			}
		}
		wrong_map(fdf, index);
		index++;
	}
	fdf->end_parse = 1;
	return (0);
}

void	wrong_map(t_fdf *fdf, int index)
{
	if ((fdf->parse[index] <= '0' || fdf->parse[index] >= '9') &&
	fdf->parse[index] != ' ' && fdf->parse[index] != '-' &&
	fdf->parse[index] != '\n')
	{
		ft_putstr("invalid map\n");
		free(fdf->parse);
		exit(0);
	}
}

int		fill_tab(t_fdf *fdf)
{
	int i;
	int j;
	int num_tmp;

	i = 0;
	j = 0;
	fdf->end_parse = 0;
	while (j < fdf->haut)
	{
		while (i < fdf->longu)
		{
			num_tmp = get_number(fdf);
			if (fdf->end_parse == 1)
				return (0);
			else
				fdf->tab[j][i] = num_tmp;
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}

void	show_tab(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < fdf->haut)
	{
		while (i < fdf->longu)
		{
			i++;
		}
		j++;
		i = 0;
	}
}

int		parser(char *argu, t_fdf *fdf)
{
	if (get_parse(argu, fdf) == -1)
		return (-1);
	if (parsing(fdf) == -1)
		return (-1);
	if (set_tab(fdf) == -1)
		return (-1);
	if (fill_tab(fdf) == -1)
		return (-1);
	return (0);
}
