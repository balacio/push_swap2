/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:09:54 by joagosti          #+#    #+#             */
/*   Updated: 2021/06/25 20:24:19 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_2(const char *str)
{
	long int	res;
	int			neg;

	res = 0;
	neg = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\f'
			|| *str == '\n' || *str == '\r' || *str == '\v'))
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && '0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		if (res > INT_MAX || res < INT_MIN)
		{
			// error_print();
			write(2, "Error\n", 6);
			exit(2);
		}
		++str;
	}
	if ((*str && !('0' <= *str && *str <= '9')))
	{
		// error_print();
		write(2, "Error\n", 6);
		exit(2);
	}
	res = res * neg;
	return (res);
}

char		*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1 + 1));
	if (!dest)
		return (0);
	i = 0;
	while (*s)
	{
		dest[i] = *s;
		s++;
		i++;
	}
	dest[i] = ' ';
	dest[i+1] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		i = 0;
		j = 0;
		if ((str = (char *)malloc(sizeof(*str) * (len + 1))))
		{
			while (s1[i])
			{
				str[i] = s1[i];
				i++;
			}
			while (s2[j])
				str[i++] = s2[j++];
			str[i] = ' ';
			str[i+1] = '\0';
			return (str);
		}
	}
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
