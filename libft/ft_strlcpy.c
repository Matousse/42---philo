/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:35:36 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/21 17:11:57 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		len;

	len = 0;
	if (*src == '\0')
	{
		*dest = '\0';
		return (0);
	}
	while (src[len])
		len++;
	if (len < 1)
		return (len);
	i = 0;
	if (n == 0)
		return (len);
	while ((i < (n - 1)) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}	
