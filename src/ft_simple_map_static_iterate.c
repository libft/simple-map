/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_static_iterate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:24:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/02 00:34:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"

#include <stdlib.h>

static bool	ft_simple_map_static_iterate_internal(
	t_ft_simple_map_static_value *arr,
	size_t depth,
	void *context,
	bool (*f)(void *value, void *context)
)
{
	size_t	i;

	depth--;
	i = -1;
	while (++i < (1 << CHAR_BIT))
		if (
			(depth
				&& arr->array[i]
				&& ft_simple_map_static_iterate_internal(arr, depth, context, f)
			)
			|| (!depth
				&& arr->value[i]
				&& f(arr->value[i], context))
		)
			return (true);
	return (false);
}

bool	ft_simple_map_static_iterate(
	t_ft_simple_map_static *self,
	void *context,
	bool (*f)(void *value, void *context)
)
{
	return (
		ft_simple_map_static_iterate_internal(
			self->values,
			self->key_length,
			context,
			f
		)
	);
}
