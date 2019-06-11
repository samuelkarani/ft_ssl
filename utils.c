/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:43:45 by smbaabu           #+#    #+#             */
/*   Updated: 2019/06/10 20:16:07 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	ft_strlen_llu(uint8_t *s)
{
	uint64_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

uint32_t	left_rotate(uint32_t n, uint32_t s)
{
	return ((n << s) | (n >> (32 - s)));
}

uint32_t	right_rotate(uint32_t n, uint32_t s)
{
	return ((n >> s) | (n << (32 - s)));
}

void		update(uint32_t *dst, uint32_t *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		dst[i] += src[i];
		i++;
	}
}

void		join_print(uint8_t *digest, char *algo, int newline)
{
	uint32_t	*sha256;
	int	i;

	i = 0;
	if (ft_strequ(algo, "MD5") || ft_strequ(algo, "md5"))
	{
		
		while (i < 16)
			ft_printf("%02x", digest[i++]);
	}
	else
	{
		sha256 = (uint32_t *)digest;
		while (i < 8)
			ft_printf("%.8x", sha256[i++]);
	}
	if (newline)
		ft_putchar('\n');
}

uint32_t	swap_int32(const uint32_t value)
{
	uint32_t result;

	result = 0;
	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return (result);
}

uint32_t	*swap_arr32(uint32_t *values, size_t bytes)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = bytes / sizeof(uint32_t);
	while (i < n)
	{
		values[i] = swap_int32(values[i]);
		i++;
	}
	return (values);
}
