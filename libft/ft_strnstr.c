/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:54:23 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/21 17:09:46 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*fretour(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	start;

	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		k = i;
		if (big[i] == little[j])
		{
			start = i;
			while ((little[j] == big[k] && little[j]) && k < len)
			{
				k++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[start]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*retour;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	if (len <= 0)
		len = -len;
	retour = fretour(big, little, len);
	if (retour == NULL)
		return (NULL);
	return (retour);
}
