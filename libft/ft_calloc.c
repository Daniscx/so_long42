/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:47:10 by dmaestro          #+#    #+#             */
/*   Updated: 2024/09/23 15:47:13 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p1;
	size_t	s;

	s = nmemb * size;
	if (size && 16711568 / size < nmemb)
		return (NULL);
	p1 = malloc(s);
	if (!p1)
		return (NULL);
	ft_bzero(p1, s);
	return (p1);
}
