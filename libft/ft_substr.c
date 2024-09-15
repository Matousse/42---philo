/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:27:04 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/21 16:58:11 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*extraction;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	extraction = (char *)malloc(sizeof(char) * (len + 1));
	if (!extraction)
		return (NULL);
	while (s[start] && i < len)
		extraction[i++] = s[start++];
	extraction[i] = '\0';
	return (extraction);
}
