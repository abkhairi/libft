/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:56 by abkhairi          #+#    #+#             */
/*   Updated: 2023/11/24 13:32:21 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nombre;
	int	signe;

	signe = 1;
	nombre = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i] != '\0'))
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '\0'))
	{
		nombre = nombre * 10 +(str[i] - '0');
		i++;
	}
	return (nombre * signe);
}

int main() {
    char str[] = "  +12345"; // Chaîne de caractères représentant un nombre entier
    int number = atoi(str); // Conversion de la chaîne en entier

    printf("La chaîne '%s' convertie en entier est : %d\n", str, number);

    return 0;
}