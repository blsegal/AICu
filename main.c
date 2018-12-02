/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:25:00 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/04 22:19:32 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static t_row	*ft_get_map_2(int fd, char *line, t_row *map)
{
	int		tmp_alums;
	int		i;

	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		if (line[i] == '\0' && fd != 0)
			return (ft_error(map));
		while (line[i])
		{
			if (!ft_isdigit(line[i]))
				return (ft_error(map));
			i++;
		}
		tmp_alums = ft_atoi(line);
		if (tmp_alums >= 1 && tmp_alums <= 10000)
			map = ft_add_row(map, tmp_alums);
		else if (line[0] == '\0' && fd == 0)
			break ;
		else
			return (ft_error(map));
		free(line);
	}
	free(line);
	return (map);
}

static t_row	*ft_get_map(char *filename)
{
	t_row				*map;
	int					fd;
	char				*line;

	map = NULL;
	line = NULL;
	if (ft_strcmp(filename, "") == 0)
		fd = 0;
	else
		fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error(map));
	map = ft_get_map_2(fd, line, map);
	return (map);
}

static char		*ft_user_start_choice(void)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	while (ft_strcmp(line, "y") != 0 && ft_strcmp(line, "n") != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	return (line);
}

int				main(int ac, char **av)
{
	t_row	*map;
	char	*line;

	map = NULL;
	if (ac > 2)
		ft_error(NULL);
	else if (ac == 2)
		map = ft_get_map(av[1]);
	else if (ac == 1)
		map = ft_get_map("");
	if (map == NULL)
		return (0);
	ft_refresh_visu(map, 0, 2);
	ft_putstr("Do you want to play first ? y/n : ");
	line = ft_user_start_choice();
	if (line[0] == 'y')
		ft_next_round(map, 1, 1);
	else
		ft_next_round(map, 1, 0);
	free(line);
	return (0);
}
