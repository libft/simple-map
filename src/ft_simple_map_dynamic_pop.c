/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_dynamic_pop.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:24:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 19:08:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"

#include <stdlib.h>

static bool	ft_simple_map_dynamic_pop_internal(
	t_ft_simple_map_dynamic **self,
	const void *key,
	size_t key_length,
	void **out
)
{
	bool	result;
	bool	need_cleanup;
	size_t	i;

	if (!key_length)
	{
		*out = (*self)->value;
		(*self)->value = NULL;
		result = !*out;
	}
	else
		result = (
				!(*self)->array[*((unsigned char *)key)]
				|| ft_simple_map_dynamic_pop_internal(
					&(*self)->array[*((unsigned char *)key)],
					((unsigned char *)key) + 1,
					key_length - 1,
					out));
	need_cleanup = !(*self)->value;
	i = -1;
	while (++i < (1 << CHAR_BIT) && need_cleanup)
		need_cleanup = !(*self)->array[i];
	free(*self);
	*self = NULL;
	return (result);
}

bool	ft_simple_map_dynamic_pop(
	t_ft_simple_map_dynamic *self,
	const void *key,
	size_t key_length,
	void **out
)
{
	if (!key_length)
	{
		*out = self->value;
		self->value = NULL;
		return (!*out);
	}
	if (!self->array[*((unsigned char *)key)])
		return (true);
	return (ft_simple_map_dynamic_pop_internal(
			&self->array[*((unsigned char *)key)],
			((unsigned char *)key) + 1,
			key_length - 1,
			out));
}
