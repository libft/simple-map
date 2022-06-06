/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_dynamic_get.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:23:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 13:36:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"

bool	ft_simple_map_dynamic_get(
	t_ft_simple_map_dynamic *self,
	const void *key,
	size_t key_length,
	void **out
)
{
	if (!key_length)
	{
		*out = self->value;
		return (!*out);
	}
	if (!self->array[*((unsigned char *)key)])
		return (true);
	return (
		ft_simple_map_dynamic_get(
			self->array[*((unsigned char *)key)],
			((unsigned char *)key) + 1,
			key_length - 1,
			out
		)
	);
}
