/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_static_set.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:01:04 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/12 02:34:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"

#include <stdlib.h>

static bool	ft_simple_map_static_set_internal(
	const t_ft_simple_map_static_set_input *context,
	t_ft_simple_map_static_value **current,
	size_t depth
)
{
	const size_t	index = ((unsigned char *) context->value)[depth];

	if (!*current)
		*current = (t_ft_simple_map_static_value *)
			malloc(sizeof(t_ft_simple_map_static_value));
	if (!*current)
		return (true);
	if (depth + 1 == context->self->key_length)
	{
		(*current)->value[index] = context->value;
		return (false);
	}
	return (
		ft_simple_map_static_set_internal(
			context,
			&(*current)->array[index],
			depth + 1
		)
	);
}

bool	ft_simple_map_static_set(
	t_ft_simple_map_static *self,
	void *key,
	void *value
)
{
	const t_ft_simple_map_static_set_input	context = {self, key, value};

	return (
		ft_simple_map_static_set_internal(
			&context,
			&self->values,
			0
		)
	);
}
