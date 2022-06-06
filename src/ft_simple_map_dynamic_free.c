/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_dynamic_free.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:13:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 19:13:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"

#include <stdlib.h>

void	ft_simple_map_dynamic_free(
	t_ft_simple_map_dynamic *self,
	void (*free_value)(void *value)
)
{
	size_t	i;

	if (self->value)
		free_value(self->value);
	i = 0;
	while (i < (1 << CHAR_BIT))
	{
		if (self->array[i])
			ft_simple_map_dynamic_free(self->array[i], free_value);
		i++;
	}
	free(self);
}
