/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:34:34 by vintran           #+#    #+#             */
/*   Updated: 2021/12/17 14:01:02 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*res;
	int		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	if (start > (unsigned int)slen)
		start = (unsigned int)slen;
	if (start + len > (unsigned int)slen)
		len = slen - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_memmove(res, s + start, len);
	res[len] = '\0';
	return (res);
}
