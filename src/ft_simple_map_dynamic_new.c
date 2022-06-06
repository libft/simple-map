/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_dynamic_new.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:18:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 13:21:39 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"

#include <stdlib.h>

static void	*ft_calloc(size_t count, size_t size)
{
	const size_t	total_size = count * size;
	char *const		result = (char *)malloc(total_size);
	size_t			i;

	if (!result)
		return (NULL);
	i = 0;
	while (i < total_size)
		result[i++] = 0;
	return (result);
}

t_ft_simple_map_dynamic	*new_ft_simple_map_dynamic(void)
{
	return ((t_ft_simple_map_dynamic *)
		ft_calloc(1, sizeof(t_ft_simple_map_dynamic)));
}
