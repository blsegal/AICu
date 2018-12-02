/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_visu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:21:53 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/04 21:44:30 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static	void	ft_print_units(unsigned short alums)
{
	ft_putstr("\t");
	while (alums > 0)
	{
		ft_putstr(" |");
		alums--;
	}
}

static	void	ft_print_hundreds(unsigned short alums)
{
	while (alums > 100)
	{
		ft_putstr("C");
		alums -= 100;
	}
	while (alums > 90)
	{
		ft_putstr("XC");
		alums -= 90;
	}
	while (alums > 50)
	{
		ft_putstr("L");
		alums -= 50;
	}
	while (alums > 40)
	{
		ft_putstr("XL");
		alums -= 40;
	}
	ft_print_units(alums);
}

static	void	ft_print_row(unsigned short alums)
{
	while (alums > 1000)
	{
		ft_putstr("M");
		alums -= 1000;
	}
	while (alums > 900)
	{
		ft_putstr("CM");
		alums -= 900;
	}
	while (alums > 500)
	{
		ft_putstr("D");
		alums -= 500;
	}
	while (alums > 400)
	{
		ft_putstr("CD");
		alums -= 400;
	}
	ft_print_hundreds(alums);
}

void			ft_refresh_visu(t_row *map, int round, int player_first)
{
	t_row	*tmp_map;

	tmp_map = map;
	if (player_first == 2)
		ft_putstr("\033[1;36m");
	else if (round % 2 == player_first)
		ft_putstr("\033[1;34m");
	else
		ft_putstr("\033[1;33m");
	ft_putstr("\n\n---------- ROUND ");
	ft_putnbr(round);
	ft_putstr(" ----------\n");
	while (tmp_map != NULL)
	{
		ft_putnbr(tmp_map->alums);
		ft_putstr("\t\t");
		ft_print_row(tmp_map->alums);
		ft_putstr("\n");
		tmp_map = tmp_map->next;
	}
	ft_putstr("\033[0;0m\n\n\n");
	ft_putstr("\033[1;36mCaption :  1000 | 500 | 100 | 50 | 10 | 1\n");
	ft_putstr("            M   |  D  |  C  | L  | X  | |\033[0;0m\n\n\n");
}
