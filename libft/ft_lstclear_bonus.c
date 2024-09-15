/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:39:47 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/21 16:54:10 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextlst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nextlst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextlst;
	}
	*lst = NULL;
}
