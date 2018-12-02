/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:36:47 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/04 22:11:17 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	ft_free_map(t_row *map)
{
	t_row	*tmp_map;

	tmp_map = NULL;
	while (map != NULL && map->next != NULL)
	{
		tmp_map = map->next;
		free(map);
		map = tmp_map;
	}
	if (map != NULL)
		free(map);
}

void	*ft_error(t_row *map)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_free_map(map);
	return (NULL);
}
