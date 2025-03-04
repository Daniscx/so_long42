/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:10:22 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/28 20:04:04 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_checkvalidpath(int x, t_info *gm);
static int	ft_look_to_the_next(char c, t_info *gm);
static int	move_gender(int x, t_info *gm);

int	keycontroller(int key, t_info *gm)
{
	if (key == W)
		move_gender(1, gm);
	if (key == S)
		move_gender(-1, gm);
	if (key == A)
		move_gender(-2, gm);
	if (key == D)
		move_gender(2, gm);
	if (key == ESC || key == X)
		finish_game(gm, 'L');
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
	static int	i = 1;

	if (c == 'C' && gm->coins != 0)
		gm->coins--;
	if (c == 'E' && gm->coins != 0)
		return (1);
	ft_printf("Moves:%i\n", i++);
	if (c == 'E' && gm->coins == 0)
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

int	finish_game(t_info *gm, char c)
{
	mlx_loop_end(gm->mlx);
	mlx_clear_window(gm->mlx, gm->wnw);
	mlx_destroy_window(gm->mlx, gm->wnw);
	if (c == 'W')
	{
		ft_printf("%s\n", "YOU WIN");
		error_detected("YOU ESCAPED!,DO YOU WANNA RUN IN THE 90'S AGAIN?\n",
			gm);
	}
	c = 'L';
	if (c == 'L')
	{
		ft_printf("%s\n", "YOU LOOOOOSE");
		error_detected("very very bad dou you wanna try a easiest map?\n", gm);
	}
	return (1);
}
