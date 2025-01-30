/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 02:38:17 by dmaestro          #+#    #+#             */
/*   Updated: 2024/12/18 19:23:05 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	write(fd, "\n", 1);
}
