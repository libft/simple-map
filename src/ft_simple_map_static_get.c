/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_static_get.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:01:04 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/12 08:18:08 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_type.h"

static bool	ft_simple_map_static_get_internal(
	const t_ft_simple_map_static_context_get *context,
	t_ft_simple_map_static_value **current,
	size_t depth
)
{
	const size_t	index = ((unsigned char *) context->key)[depth];

	if (!*current)
		return (true);
	if (depth + 1 == context->self->key_length)
	{
		if (!(*current)->value[index])
			return (true);
		if (context->out)
			*context->out = (*current)->value[index];
		return (false);
	}
	return (
		ft_simple_map_static_get_internal(
			context,
			&(*current)->array[index],
			depth + 1
		)
	);
}

bool	ft_simple_map_static_get(
	t_ft_simple_map_static *self,
	const void *key,
	void **out
)
{
	const t_ft_simple_map_static_context_get	context = {self, key, out};

	return (
		ft_simple_map_static_get_internal(
			&context,
			&self->values,
			0
		)
	);
}
