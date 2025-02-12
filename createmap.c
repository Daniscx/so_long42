/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:30:07 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/10 19:30:12 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_createmap(t_info *gm)
{
	int	y;
	int	x;
	y = 0;

	while (gm->map[y])
	{
		x = 0;
		while (gm->map[y][x])
		{
			if (ft_strchr("P1CE0", gm->map[y][x]))
				ft_putintowindos(gm, (gm->map[y][x]), x, y);
			x++;
		}
		y++;
	}
}

void	ft_putintowindos(t_info *gm, char c, int x, int y)
{
	ft_printf("%shola","hola");
	if(c != '1')
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->backgroung,(x*32), (y*32));
	if (c == 'P')
	{
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->ply_right,
			(x*32), (y*32));
		gm->p_x = x;
		gm->p_y = y;
	}
	if (c == 'C')
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->rings, x*32,y*32);
	if (c == '1')
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->wall, x*32, y*32);

	if (c == 'E')
		{
			mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->exc0, x*32,y*32);
			gm->e_y = y;
			gm->e_x = x;
		}
}
void	ft_image(t_info *gm)
{
	char	*path;
	int		weith;
	int		hight;

	path = "/home/dmaestro/so_long/textures/front_player.xpm";
	gm->sprite->ply_front = mlx_xpm_file_to_image(gm->mlx, path, &weith,
			&hight);
	path = "/home/dmaestro/so_long/textures/back_player.xpm";
	gm->sprite->ply_back = mlx_xpm_file_to_image(gm->mlx, path, &weith, &hight);
	path = "/home/dmaestro/so_long/textures/left_player.xpm";
	gm->sprite->ply_left = mlx_xpm_file_to_image(gm->mlx, path, &weith, &hight);
	path = "/home/dmaestro/so_long/textures/rirght_player.xpm";
	gm->sprite->ply_right = mlx_xpm_file_to_image(gm->mlx, path, &weith,
			&hight);
	path = "/home/dmaestro/so_long/textures/eixt0.xpm";
	gm->sprite->exc0 = mlx_xpm_file_to_image(gm->mlx, path, &weith, &hight);
	path = "/home/dmaestro/so_long/textures/exit1.xpm";
	gm->sprite->exc1 = mlx_xpm_file_to_image(gm->mlx, path, &weith, &hight);
	path = "/home/dmaestro/so_long/textures/coins.xpm";
	gm->sprite->rings = mlx_xpm_file_to_image(gm->mlx, path, &weith, &hight);
	path = "/home/dmaestro/so_long/textures/wall .xpm";
	gm->sprite->wall = mlx_xpm_file_to_image(gm->mlx, path, &weith, &hight);
	path = "/home/dmaestro/so_long/textures/background.xpm";
	gm->sprite->backgroung = mlx_xpm_file_to_image(gm->mlx, path, &weith,
			&hight);
}

