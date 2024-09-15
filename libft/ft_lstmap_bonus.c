/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:54:36 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/21 16:57:32 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nouvelle;
	t_list	*temp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	nouvelle = NULL;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			del(content);
			ft_lstclear(&nouvelle, del);
			return (NULL);
		}
		ft_lstadd_back(&nouvelle, temp);
		lst = lst->next;
	}
	temp->next = NULL;
	return (nouvelle);
}
