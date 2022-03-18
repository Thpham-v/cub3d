/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:18:43 by vintran           #+#    #+#             */
/*   Updated: 2021/12/17 13:53:25 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	void	*dest;

	dest = malloc(count * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, count * size);
	return (dest);
}
