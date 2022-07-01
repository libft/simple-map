/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_dynamic_iterate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:24:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/02 00:38:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"

#include <stdlib.h>

bool	ft_simple_map_dynamic_iterate(
	t_ft_simple_map_dynamic *self,
	void *context,
	bool (*f)(void *value, void *context)
)
{
	size_t	i;

	if (self->value && f(self->value, context))
		return (true);
	i = -1;
	while (++i < (1 << CHAR_BIT))
		if (
			self->array[i]
			&& ft_simple_map_dynamic_iterate(self->array[i], context, f)
		)
			return (true);
	return (false);
}
