/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:32:11 by vintran           #+#    #+#             */
/*   Updated: 2022/03/19 02:34:21 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		s1len;
	int		s2len;
	int		reslen;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	reslen = s1len + s2len;
	res = malloc(sizeof(char) * (reslen + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, s1len);
	ft_memcpy(&res[s1len], s2, s2len);
	res[reslen] = '\0';
	return (res);
}
