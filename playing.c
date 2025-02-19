/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:10:22 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/19 19:55:59 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		ft_checkvalidpath(int x, t_info *gm);
static int		ft_look_to_the_next(char c, t_info *gm);
static int		move_gender(int x, t_info *gm);
static void	finish_game(t_info *gm, char c);

int	keycontroller(int key, t_info *gm)
{
	if (key == W)
	{
			move_gender(1, gm);
			ft_printf("%s", "↑");
	}		
	if (key == S)
	{
			move_gender(-1, gm);
			ft_printf("%s", "↓");
	}		
	if (key == A)
	{
			move_gender(-2, gm);
			ft_printf("%s", "←");
	}		
	if (key == D)
	{
			move_gender(2, gm);
			ft_printf("%s", "→");
	}		
	if (key == ESC)
		finish_game(gm, W);
	return (1);
}
static int	move_gender(int x, t_info *gm)
{
	if (ft_checkvalidpath(x, gm) != 0)
		return (0);
	mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->backgroung, gm->p_x
		* 32, gm->p_y * 32);
	if (x == 2 || x == -2)
	{
		gm->p_x = gm->p_x + (x / 2);
		if (x == 2)
			mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->ply_right,
				gm->p_x * 32, gm->p_y * 32);
		if (x == -2)
			mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->ply_left,
				gm->p_x * 32, gm->p_y * 32);
	}
	if (x == 1 || x == -1)
	{
		gm->p_y = gm->p_y - x;
		if (x == -1)
			mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->ply_front,
				gm->p_x * 32, gm->p_y * 32);
		if (x == 1)
			mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->ply_back,
				gm->p_x * 32, gm->p_y * 32);
	}
	return (1);
}
static int	ft_checkvalidpath(int x, t_info *gm)
{
	if (x == 1 && (gm->map[gm->p_y - 1][gm->p_x]) != '1')
		return (ft_look_to_the_next(gm->map[gm->p_y - 1][gm->p_x], gm));
	if (x == -1 && (gm->map[gm->p_y + 1][gm->p_x]) != '1')
		return (ft_look_to_the_next(gm->map[gm->p_y + 1][gm->p_x], gm));
	if (x == 2 && (gm->map[gm->p_y][gm->p_x + 1]) != '1')
		return (ft_look_to_the_next(gm->map[gm->p_y][gm->p_x + 1], gm));
	if (x == -2 && (gm->map[gm->p_y][gm->p_x - 1]) != '1')
		return (ft_look_to_the_next(gm->map[gm->p_y][gm->p_x - 1], gm));
	return (1);
}
static int	ft_look_to_the_next(char c, t_info *gm)
{
	if (c == 'C' && gm->coins != 0)
		gm->coins--;
	if (c == 'E' && gm->coins != 0)
		return (1);
	else if (c == 'E' && gm->coins == 0)
	{
		finish_game(gm, 'W');
		return (0);
	}
	if (gm->coins == 0)
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->exc1, gm->e_x
			* 32, gm->e_y * 32);
	gm->map[gm->p_y][gm->p_x] = '0';
	return (0);
}
static void	finish_game(t_info *gm, char c)
{
	mlx_loop_end(gm->mlx);
	mlx_clear_window(gm->mlx, gm->wnw);
	mlx_destroy_window(gm->mlx, gm->wnw);
	if (c == 'W')
		ft_printf("%s",
																																																																																													"----------------------------------------\n|										|\n|										|\n|										|\n|										|\n|										|\n|										|\n|										|\n|										|\n|										|\n|                                      |\n--------------------------------");
	error_detected("you escaped with the TOYOTA COROLLA DO YOU WANNA RUN IN THE 90'S AGAIN?",
		gm);
}