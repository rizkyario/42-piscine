/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 02:14:33 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/10 14:21:45 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = dest;
	while (*ptr1)
		ptr1++;
	ptr2 = src;
	while (*ptr2)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
	}
	*ptr1 = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		len;
	int		i;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len = len + ft_strlen(argv[i]);
		i++;
	}
	str = (char*)malloc(sizeof(*str) * (len + 1));
	i = 1;
	while (i < argc)
	{
		if (i != 1)
			str = ft_strcat(str, "\n");
		str = ft_strcat(str, argv[i]);
		i++;
	}
	return (str);
}
