/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 21:04:16 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/04 21:59:03 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static t_row	*ft_get_current_row(t_row *map)
{
	t_row	*last_row;

	last_row = map;
	while (last_row->next != NULL)
		last_row = last_row->next;
	return (last_row);
}

static t_row	*ft_check_empty_row(t_row *map)
{
	t_row *last_row;
	t_row *tmp;

	tmp = map;
	last_row = ft_get_current_row(map);
	if (last_row->alums == 0)
	{
		if (tmp == last_row)
		{
			free(last_row);
			return (NULL);
		}
		while (tmp->next != last_row)
			tmp = tmp->next;
		free(tmp->next);
		tmp->next = NULL;
	}
	return (map);
}

static void		ft_end_game(int round, int player_first)
{
	if (round % 2 == player_first)
		ft_putstr("\033[1;32mYOU WON\033[0;0m\n");
	else
		ft_putstr("\033[1;31mYOU LOST\033[0;0m\n");
}

void			ft_next_round(t_row *map, int round, int player_first)
{
	t_row	*last_row;

	map = ft_check_empty_row(map);
	if (map != NULL)
	{
		last_row = ft_get_current_row(map);
		ft_refresh_visu(map, round, player_first);
		ft_putstr("\033[0m");
		if (round % 2 == player_first)
		{
			ft_putstr("YOUR TURN\nChoose 1 to 3 matches to delete\n");
			last_row = ft_player_play(last_row);
		}
		else
		{
			ft_putstr("COMPUTER TURN\nPress enter to continue\n");
			last_row = ft_ai_play(last_row);
		}
		ft_next_round(map, round + 1, player_first);
	}
	else
		ft_end_game(round, player_first);
}
