/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:25:02 by vintran           #+#    #+#             */
/*   Updated: 2021/01/04 14:48:52 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst)
	{
		ft_lstclear(&(*lst)->next, del);
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
