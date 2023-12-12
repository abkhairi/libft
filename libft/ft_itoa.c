/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:35:39 by abkhairi          #+#    #+#             */
/*   Updated: 2023/12/04 10:07:50 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	long	ft_count_nbr(int long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int long	count_nbr;
	int long	num;

	num = n;
	count_nbr = ft_count_nbr(num);
	printf("count nbr => %ld\n", count_nbr);
	str = malloc(sizeof(char) * count_nbr + 1);
	if (str == NULL)
		return (NULL);
	str[count_nbr] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[count_nbr - 1] = (num % 10) + 48;
		num = num / 10;
		count_nbr--;
	}
	return (str);
}
int main() {
    int number = 0;
    char *str = ft_itoa(number);
    if (str != NULL) {
        printf("Conversion de %d en chaîne de caractères : %s\n", number, str);
        free(str); // Ne pas oublier de libérer la mémoire allouée dynamiquement
    } else {
        printf("Allocation de mémoire échouée.\n");
    }
    return 0;
}