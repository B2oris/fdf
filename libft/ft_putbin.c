/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 04:38:40 by beborch           #+#    #+#             */
/*   Updated: 2017/12/21 14:17:28 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbin(char *str)
{
	int		byte;
	char	c;

	while (str && *str && (byte = 8))
	{
		while (--byte >= 0)
		{
			c = ((*str >> byte) % 2) + 48;
			write(1, &c, 1);
		}
		write(1, (++str && *str ? " " : "\n"), 1);
	}
}
