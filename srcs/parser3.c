/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:46:48 by beborch           #+#    #+#             */
/*   Updated: 2018/10/11 15:41:45 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*ft_strjoin_del(const char *s1, char const *s2, int j)
{
	int		i;
	char	*str;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)ft_memalloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str = ft_strcat(str, (char *)s1);
	str = ft_strcat(str, (char *)s2);
	str[i] = '\0';
	if (j == 1 || j == 3)
		free((void*)s1);
	if (j == 2 || j == 3)
		free((void*)s2);
	return (str);
}

int			get_parse(char *argu, t_fdf *fdf)
{
	char	*tmp;
	int		i;

	i = 0;
	fdf->file = open(argu, O_RDONLY);
	ft_bzero(fdf->buff, BUFF_SIZE);
	fdf->parse = ft_strdup("");
	while ((fdf->ret = read(fdf->file, fdf->buff, BUFF_SIZE)) > 0)
	{
		if (fdf->ret != 0)
			fdf->buff[fdf->ret] = '\0';
		fdf->parse = ft_strjoin_del(fdf->parse, fdf->buff, 1);
	}
	if (fdf->ret == -1)
		return (-1);
	return (0);
}

void		set_struct(t_fdf *fdf)
{
	fdf->parse = NULL;
	fdf->zoom = 0;
	fdf->ret = 2;
	fdf->longu = 0;
	fdf->haut = 0;
	fdf->move_x = 00;
	fdf->move_y = 00;
	fdf->move_high_x = 00;
	fdf->move_high_y = 00;
	fdf->zoom = 1;
	fdf->zoom_tracing = 0;
	fdf->x = NULL;
	fdf->y = NULL;
	fdf->tab = NULL;
}
