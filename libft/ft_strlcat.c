/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:51:47 by dmathis           #+#    #+#             */
/*   Updated: 2024/05/21 17:12:46 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
//#include <string.h>
//#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dest_alloc_size)
{
	size_t	isrc;
	size_t	dlen;
	size_t	slen;

	isrc = 0;
	dlen = 0;
	slen = 0;
	if (dest_alloc_size == 0 && (!dest || !src))
		return (0);
	while (dest[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (dlen >= dest_alloc_size)
		return (slen + dest_alloc_size);
	while (src[isrc] && (isrc < (dest_alloc_size - dlen - 1)))
	{
		dest[dlen + isrc] = src[isrc];
		isrc++;
	}
	dest[dlen + isrc] = '\0';
	return (dlen + slen);
}
/*
// Fonction pour tester strlcat
void test_strlcat(char *dst, const char *src, size_t dstsize) {
    size_t result = ft_strlcat(dst, src, dstsize);

    // Affiche le résultat de la concatenation
    printf("Destination après strlcat: '%s'\n", dst);
    // Affiche la longueur totale de la chaîne qu'on voulait créer
    printf("Longueur totale voulue: %zu\n", result);

    // Vérifie si la concatenation s'est bien passée
    if (result >= dstsize) {
        printf("Attention: la chaîne a été tronquée.\n");
    } else {
        printf("La chaîne a été concaténée sans être tronquée.\n");
    }
}

int main() {
    char buffer[20] = "Hello";
    const char *to_append = ", world!";

    // Affiche l'état initial du buffer
    printf("Buffer initial: '%s'\n", buffer);

    // Appelle la fonction de test
    test_strlcat(buffer, to_append, sizeof(buffer));

    return 0;
}*/
