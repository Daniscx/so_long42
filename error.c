/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:09:28 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/21 19:20:46 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroyer(t_info *gm);

void	free_double_pointer(char **map)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (map[y])
		y++;
	y--;
	while (y >= 0)
	{
		free(map[y]);
		y--;
	}
	free(map);
}
void	error_detected(const char *error, t_info *gm)
{
	ft_printf("%s", error);
	if (gm && gm->map != NULL)
		free_double_pointer(gm->map);
	if (gm && gm->sprite)
		destroyer(gm);
	if (gm && gm->mlx)
	{
		mlx_destroy_display(gm->mlx);
		free(gm->mlx);
	}
}
static void	destroyer(t_info *gm)
{
	if (!gm->sprite)
		return ;
	if (gm->sprite->backgroung)
		mlx_destroy_image(gm->mlx, gm->sprite->backgroung);
	if (gm->sprite->wall)
		mlx_destroy_image(gm->mlx, gm->sprite->wall);
	if (gm->sprite->rings)
		mlx_destroy_image(gm->mlx, gm->sprite->rings);
	if (gm->sprite->ply_front)
		mlx_destroy_image(gm->mlx, gm->sprite->ply_front);
	if (gm->sprite->ply_back)
		mlx_destroy_image(gm->mlx, gm->sprite->ply_back);
	if (gm->sprite->ply_left)
		mlx_destroy_image(gm->mlx, gm->sprite->ply_left);
	if (gm->sprite->ply_right)
		mlx_destroy_image(gm->mlx, gm->sprite->ply_right);
	if (gm->sprite->exc1)
		mlx_destroy_image(gm->mlx, gm->sprite->exc1);
	if (gm->sprite->exc0)
		mlx_destroy_image(gm->mlx, gm->sprite->exc0);
	free(gm->sprite);
	gm->sprite = NULL;
}
void	get_the_original(t_info *gm, char c)
{
	char	old;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (c == 'i')
		old = 'C';
	else if (c == 'o')
		old = '0';
	gm->map[gm->p_y][gm->p_x] = 'P';
	while (gm->map[i])
	{
		x = 0;
		while (gm->map[i][x])
		{
			if (gm->map[i][x] == c)
				gm->map[i][x] = old;
			x++;
		}
		i++;
	}
}
