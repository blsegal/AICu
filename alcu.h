/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:32:48 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/04 22:15:08 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

typedef	struct		s_row
{
	char			strat;
	unsigned short	alums;
	struct s_row	*next;
}					t_row;

t_row				*ft_add_row(t_row *map, unsigned short alums);
void				ft_next_round(t_row *map, int round, int player_first);
void				ft_refresh_visu(t_row *map, int round, int player_first);

t_row				*ft_ai_play(t_row *last_row);
t_row				*ft_player_play(t_row *last_row);

void				ft_free_map(t_row *map);
void				*ft_error(t_row *map);

#endif
