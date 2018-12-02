/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:44:38 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/04 22:01:14 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

t_row	*ft_ai_play(t_row *last_row)
{
	int		to_delete;
	int		random;
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	free(line);
	random = (int)((long)(&random) % 3) + 1;
	if (last_row->strat == 0)
		to_delete = last_row->alums % 4;
	else
	{
		to_delete = (last_row->alums % 4) - 1;
		if (to_delete == -1)
			to_delete = 3;
	}
	if (to_delete == 0)
	{
		if (last_row->alums >= random)
			to_delete = random;
		else
			to_delete = last_row->alums;
	}
	last_row->alums -= to_delete;
	return (last_row);
}

t_row	*ft_player_play(t_row *last_row)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	while (ft_atoi(line) < 1 || ft_atoi(line) > 3 ||
			ft_atoi(line) > last_row->alums)
	{
		free(line);
		get_next_line(0, &line);
	}
	last_row->alums -= (unsigned short)ft_atoi(line);
	free(line);
	return (last_row);
}
