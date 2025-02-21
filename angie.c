/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angie.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:08:48 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/21 18:55:38 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_checkwalls(t_info *gm);
static int	ft_counter(char **map, char c, t_info *gm);
static void	ft_posible_exit(t_info *gm, int y, int x);
static void	colums(t_info *gm, int y);

void	checkmapping(t_info *gm)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	if (!gm)
		return ;
	y = 0;
	while (gm->map[y])
	{
		x = 0;
		while (gm->map[y][x] && (x < gm->size_x - 2))
		{
			if (!ft_strchr("10CPE", gm->map[y][x]))
				error_detected("il n'est pas  usable sprite", gm);
			x++;
		}
		y++;
	}
	if ((gm->coins = ft_counter(gm->map, 'C', gm)) == 0)
		error_detected("Check the amount of rings in the map", gm);
	ft_counter(gm->map, 'E', gm);
	ft_counter(gm->map, 'P', gm);
	ft_checkwalls(gm);
	ft_posible_exit(gm, gm->p_y, gm->p_x);
}

static int	ft_counter(char **map, char c, t_info *gm)
{
	int		o;
	int		y;
	char	*p;

	o = 0;
	y = 0;
	p = NULL;
	if (!map)
		return (0);
	while (map[y])
	{
		p = map[y];
		while (ft_strchr(p, c))
		{
			o++;
			p = ft_strchr(p, c) + 1;
			gm->p_x = p - gm->map[y];
			gm->p_y = y;
		}
		y++;
	}
	if ((c == 'P' || c == 'E') && o != 1)
		error_detected("check the amount of players or exits please", gm);
	return (o);
}

static void	ft_checkwalls(t_info *gm)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (gm->map[0][x + 1])
	{
		if (gm->map[0][x] != '1')
			error_detected("there is a bad box of wall , please cheack it", gm);
		x++;
	}
	colums(gm, 0);
	x = 0;
	y = gm->size_y - 1;
	while (gm->map != NULL && gm->map[y][x])
	{
		if (gm->map[y][x] != '1')
			error_detected("there is a bad box of wall , please cheack it", gm);
		x++;
	}
}
static void	colums(t_info *gm, int y)
{
	if (gm->sprite == NULL)
		return ;
	while (gm->map[y + 1])
	{
		if (gm->map[y][0] != '1')
			error_detected("there is a bad box of wall , please cheack it", gm);
		if (gm->map != NULL && gm->map[y][gm->size_x - 2] != '1')
			error_detected("there is a bad box of wall , please cheack it", gm);
		y++;
	}
}
static void	ft_posible_exit(t_info *gm, int y, int x)
{
	int	i;

	i = gm->coins;
	if (gm->map[y][x] == '1' || gm->map[y][x] == 'E' || gm->map[y][x] == 'o'
		|| gm->map[y][x] == 'i')
		return ;
	if (gm->map[y][x] == 'C')
	{
		gm->coins--;
		gm->map[y][x] = 'i';
	}
	else
		gm->map[y][x] = 'o';
	ft_posible_exit(gm, y + 1, x);
	ft_posible_exit(gm, y - 1, x);
	ft_posible_exit(gm, y, x + 1);
	ft_posible_exit(gm, y, x - 1);
	if (x == gm->p_x && y == gm->p_y && gm->coins != 0)
		error_detected("the baby can't scape cheeater", gm);
	else if (x == gm->p_x && y == gm->p_y && gm->coins == 0)
	{
		gm->coins = i;
		get_the_original(gm, 'o');
		get_the_original(gm, 'i');
	}
}

