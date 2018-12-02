/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:42:27 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/04 21:55:03 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static char	ft_determine_strat(t_row *prev_row)
{
	if (prev_row == NULL)
		return (1);
	if (prev_row->alums % 4 == prev_row->strat)
		return (0);
	else
		return (1);
}

t_row		*ft_add_row(t_row *map, unsigned short alums)
{
	t_row	*new_row;
	t_row	*prev_row;

	prev_row = map;
	while (prev_row != NULL && prev_row->next != NULL)
		prev_row = prev_row->next;
	if (!(new_row = (t_row*)malloc(sizeof(t_row))))
		return (NULL);
	new_row->strat = ft_determine_strat(prev_row);
	new_row->alums = alums;
	new_row->next = NULL;
	if (prev_row != NULL)
	{
		prev_row->next = new_row;
		return (map);
	}
	else
		return (new_row);
}
