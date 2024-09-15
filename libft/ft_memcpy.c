/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:48:18 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/21 17:20:42 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (0);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*
int	main() 

{
    // Déclaration des tableaux source et destination
	char src[] = "Hello, world!";
	char dest[50]; // Assurez-vous que la destination est assez grande

    // Utilisation de memcpy pour copier le contenu de src vers dest
	ft_memcpy(dest, src, 14); // +1 pour inclure le caractère nul de fin de chaîne

    // Affichage du résultat
	printf("%s", dest);
   
   return 0;
}*/
