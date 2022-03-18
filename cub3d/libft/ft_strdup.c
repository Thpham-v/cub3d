/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:31:58 by vintran           #+#    #+#             */
/*   Updated: 2021/12/17 14:01:42 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		slen;

	slen = ft_strlen(s);
	dst = malloc(sizeof(char) * (slen + 1));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s, slen);
	dst[slen] = '\0';
	return (dst);
}
