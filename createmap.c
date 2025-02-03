/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:30:07 by dmaestro          #+#    #+#             */
/*   Updated: 2025/01/30 18:02:28 by dmaestro         ###   ########.fr       */
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
			if (ft_strchr("P10CE", gm->map[y][x]))
				ft_putintowindos(gm, (gm->map[y][x]), x, y);
			x++;
		}
		y++;
	}
}

void	ft_putintowindos(t_info *gm, char c, int x, int y)
{
	mlx_destroy_image(gm->mlx,gm->sprite->wall);
	ft_printf("%shola","hola");
	if (c == 'P')
	{
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->ply_front,
			(gm->size_x / x), (gm->size_y / y));
		gm->p_x = x;
		gm->p_y = y;
	}
	if (c == 'C')
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->rings, x*32,y*32);
	if (c == '1')
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->rings, x*32, y*32);
	if (c == '0')
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->backgroung, x*32, y*32);
	if (c == 'E')
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->exc0, x*32,y*32);
}
