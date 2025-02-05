/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:10:22 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/05 20:12:38 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkvalidpath(int x, t_info *gm);
int	ft_look_to_the_next(char c, t_info *gm);
int	move_gender(int x, t_info *gm);

int	*keycontroller(int key, t_info *gm)
{
	int *i = NULL;
	
	*i = 1;
	if (key == W)
		move_gender(1, gm);
	if (key == S)
		move_gender(-1, gm);
	if (key == A)
		move_gender(-2, gm);
	if (key == D)
		move_gender(2, gm);
	return(i);
}
int	move_gender(int x, t_info *gm)
{
	if (ft_checkvalidpath(x, gm) != 0)
		return(0);
	mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->backgroung, gm->p_x,
		gm->p_y);
	if (x == 2 || x == -2)
	   	gm->p_x  =gm->p_x + (x / 2);
	if (x == 1 || x == -1)
		gm->p_y	= gm->p_y + x;
	mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->ply_right, gm->p_x,
		gm->p_y);
	return(1);
}
int	ft_checkvalidpath(int x, t_info *gm)
{
	if (x == 1 && (gm->map[gm->p_y + 1][gm->p_x]) != '1')
		return (ft_look_to_the_next(gm->map[gm->p_y + 1][gm->p_x], gm));
	if (x == -1 && (gm->map[gm->p_y - 1][gm->p_x]) != '1')
		return (ft_look_to_the_next(gm->map[gm->p_y - 1][gm->p_x], gm));
	if (x == 2 && (gm->map[gm->p_y][gm->p_x + 1]) != '1')
		return (ft_look_to_the_next(gm->map[gm->p_y][gm->p_x + 1], gm));
	if (x == 2 && (gm->map[gm->p_y][gm->p_x - 1]) != '1')
		return (ft_look_to_the_next(gm->map[gm->p_y][gm->p_x - 1], gm));
	return (1);
}
int	ft_look_to_the_next(char c, t_info *gm)
{
	if (c == 'C')
		gm->coins--;
	if (c == 'E' && gm->coins != 0)
		return (1);
	return (0);
}