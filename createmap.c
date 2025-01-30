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

#include   "so_long.h"
void    ft_createmap(t_info *gm)
{
    int y;
	int	x;
	while(gm->map[y])
	{
		x = 0;
		while(gm->map[y][x])
		{	
			if(ft_strchr("P10CE",gm->map[y][x]))
				ft_putintowindos(gm,gm->map[x][y], x, y);
			x++;
		}
		y++;
	}
}
void   ft_putintowindos(t_info	*gm, char c,int x, int y)
{
	if(c == 'P')
	{
		mlx_put_image_to_window(gm->mlx, gm->wnw, gm->sprite->ply_front, x, y);
		gm->p_x = x;
		gm->p_y = y;
	}
	if(c == 'C')
		mlx_put_image_to_window(gm->mlx, gm->wnw,gm->sprite->rings,x,y);
	if(c == '1')
		mlx_put_image_to_window(gm->mlx, gm->wnw,gm->sprite->wall,x,y);
	if(c == '0')
		mlx_put_image_to_window(gm->mlx, gm->wnw,gm->sprite->backgroung, x, y);
	if(c == 'E')
		mlx_put_image_to_window(gm->mlx, gm->wnw,gm->sprite->exc0 , x, y);

}