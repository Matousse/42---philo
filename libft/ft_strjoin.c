/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:29:24 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/16 12:27:40 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i_s1;
	int		i_s2;
	char	*dest;

	i_s1 = 0;
	i_s2 = 0;
	while (s1[i_s1])
		i_s1++;
	while (s2[i_s2])
		i_s2++;
	dest = malloc(sizeof(char) * (i_s1 + i_s2) + 1);
	if (dest == NULL)
		return (NULL);
	i_s1 = -1;
	i_s2 = 0;
	while (s1[++i_s1])
		dest[i_s1] = s1[i_s1];
	while (s2[i_s2])
		dest[i_s1++] = s2[i_s2++];
	dest[i_s1] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	s1[5] = "aaaa";
	char	s2[5] = "bbbb";
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	printf("%s", s3);
	return (0);
}*/
