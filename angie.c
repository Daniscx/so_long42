/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angie.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:08:48 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/18 19:49:53 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void ft_checkwalls(t_info *gm);
static int ft_counter(char **map, char c);
static int ft_counter(char **map, char c);

void checkmapping(t_info *gm)
{
    int y;
    int x;
     x = 0;
	 y = 0;
    if(!gm)
		return;
	y = 0;
    while(gm->map[y] )
    {
        x = 0;
        while(gm->map[y][x]&& (x < gm->size_x - 2))
        {
            if(!ft_strchr("10CPE", gm->map[y][x]))
                error_detected("il n'est pas  usable sprite", gm);
            x++;
        }
        y++;
    }
    if(ft_counter(gm->map , 'P') != 1)
        error_detected("Check the amount of players in the map", gm);
    if(ft_counter(gm->map , 'E') != 1)
        error_detected("Check the amount of exits in the map", gm);
    if((gm->coins = ft_counter(gm->map , 'C')) == 0)
        error_detected("Check the amount of rings in the map", gm);
    ft_checkwalls(gm);
}
static int ft_counter(char **map, char c)
{
    int o;
    int y;
    char *p;
	o = 0;
	y = 0;
	p = NULL;
    if(!map)
        return(0);
    while(map[y])
    {   
        p = map[y];
        while(ft_strchr(p , c))
        {
            o++;
            p = ft_strchr(p, c) + 1;
        }
        y++;
    }
    return(o);
}
static void ft_checkwalls(t_info *gm)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(gm->map[0][x + 1])
    {
        if(gm->map[0][x] != '1')
            error_detected("there is a bad box of wall , please cheack it", gm);
        x++;
    }
    x = 0;
    while(gm->map[y + 1])
    {
            if(gm->map[y][0] != '1')
            error_detected("there is a bad box of wall , please cheack it", gm);
            if(gm->map[y][gm->size_x - 2] != '1')
            error_detected("there is a bad box of wall , please cheack it", gm);
        y++;
    }
	x = 0;

    while(gm->map[y][x])
    {
        if(gm->map[y][x] != '1')
            error_detected("there is a bad box of wall , please cheack it", gm);
        x++;
    }
    
}
