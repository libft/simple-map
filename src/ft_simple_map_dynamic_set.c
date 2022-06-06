/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_dynamic_set.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:24:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 19:46:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"
#include "ft_simple_map.h"

#include <stdlib.h>

bool	ft_simple_map_dynamic_set(
	t_ft_simple_map_dynamic *self,
	const void *key,
	size_t key_length,
	void *value
)
{
	bool	fresh;
	bool	result;

	if (!key_length && self->value)
		return (true);
	if (!key_length)
		self->value = value;
	if (!key_length)
		return (false);
	fresh = !self->array[*((unsigned char *)key)];
	if (fresh)
		self->array[*((unsigned char *)key)] = new_ft_simple_map_dynamic();
	if (!self->array[*((unsigned char *)key)])
		return (true);
	result = ft_simple_map_dynamic_set(
			self->array[*((unsigned char *)key)],
			((unsigned char *)key) + 1,
			key_length - 1,
			value);
	if (fresh && result)
	{
		free(self->array[*((unsigned char *)key)]);
		self->array[*((unsigned char *)key)] = NULL;
	}
	return (result);
}
