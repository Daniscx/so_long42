/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:47:10 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/12 19:22:27 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p1;
	size_t	s;
	size_t	i;

	i = 0;
	s = nmemb * size;
	if (s >= 16711568 || s <= 0)
		return (NULL);
	p1 = malloc(s + 1);
	if (!p1)
		return (NULL);
	while (i <= s)
	{
		p1[i] = 0;
		i++;
	}
	return (p1);
}
