/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:40:56 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/18 14:43:40 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned	int	i;
	char			*ret;

	i = 0;
	ret = (char*)s;
	if (n > 0)
	{
		while (++i < n + 1)
			ret[i - 1] = 0;
	}
}
