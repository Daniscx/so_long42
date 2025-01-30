/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:07:59 by dmaestro          #+#    #+#             */
/*   Updated: 2025/01/30 18:02:28 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
 #define SO_LONG_H
# include "minilibx/minilibx-linux/mlx.h"
# include "libft/libft.h"

# define  WALL = 1
# define  COINS = C 
# define  PLAYER = P 
# define  EXIT = E
# define  BACK_ROUND = 0

# define ESC = 653607
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

typedef struct  s_img

{
    void	*ply_front;
	void	*ply_left;
    void    *ply_right;
    void    *ply_back;
    void    *backgroung;
	void	*exc0;
  void  *exc1;
	void	*rings;
  void  *wall;

} t_img;


typedef struct s_info
{
  char **map;
  void    *mlx;
  int    size_y;
  int    size_x;
  int	p_y;
  int   p_x;
  t_img  *sprite;
  void	*wnw;
  int	coins;

}   t_info;

void mapping(t_info *gm, char *arg);
int main(int argc, char **argv);
void ft_extracting(char *arg, t_info *gm);
void error_detected(const char *error, t_info *gm);
void checkmapping(t_info *gm);



#endif

