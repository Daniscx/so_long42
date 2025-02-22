/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:17:04 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/22 20:22:27 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_extracting(char *arg, t_info *gm)
{
	int	i;
	int	fd;

	if (!gm)
		return ;
	fd = open(arg, O_RDONLY);
	i = 0;
	gm->map = NULL;
	gm->map = ft_calloc(gm->size_y + 1, sizeof(char *));
	if (gm->map == NULL)
		error_detected("mapping error", gm);
	while (i < gm->size_y)
	{
		gm->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	ft_sizegt(char *arg, t_info *gm)
{
	int		fd;
	char	*line;
	int		i;
	int		x;

	x = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_detected("il n'est pas fd", gm);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i])
			i++;
		if (gm->size_x == 0)
			gm->size_x = i;
		x += i;
		gm->size_y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if ((gm->size_x <= gm->size_y) || ((x + 1 )/ gm->size_y != gm->size_x))
		error_detected("It isnt a rectangle", gm);
}

t_sprite	*ft_init_image(void)
{
	t_sprite	*img;

	img = NULL;
	img = malloc(sizeof(t_sprite));
	img->exc0 = NULL;
	img->wall = NULL;
	img->backgroung = NULL;
	img->rings = NULL;
	img->ply_right = NULL;
	img->ply_left = NULL;
	img->ply_front = NULL;
	img->ply_back = NULL;
	img->exc1 = NULL;
	return (img);
}

t_info	*ft_inicialitated(void)
{
	t_info	*gm;

	gm = NULL;
	gm = malloc(sizeof(t_info));
	gm->map = NULL;
	gm->size_x = 0;
	(gm->mlx) = NULL;
	gm->size_y = 0;
	gm->p_x = 0;
	gm->p_y = 0;
	gm->wnw = NULL;
	gm->sprite = ft_init_image();
	gm->e_y = 0;
	gm->e_x = 0;
	return (gm);
}

void	mapping(t_info *gm, char *arg)
{
	if (ft_strncmp(arg + ft_strlen(arg) - 4, ".ber", 4) != 0)
		error_detected("Le type pour le fd il n'est\n", gm);
	if (gm->sprite == NULL)
		return ;
	ft_sizegt(arg, gm);
	ft_extracting(arg, gm);
	if (gm->map == NULL)
		error_detected("mappicitation il n'est pas bian estructuré\nº", gm);
}
