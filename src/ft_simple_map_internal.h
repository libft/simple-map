/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:42:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/12 02:27:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLE_MAP_INTERNAL_H
# define FT_SIMPLE_MAP_INTERNAL_H

# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

# include "ft_simple_map.h"

typedef union u_ft_simple_map_static_value
{
	void								*value[1 << CHAR_BIT];
	union u_ft_simple_map_static_value	*array[1 << CHAR_BIT];
}	t_ft_simple_map_static_value;

typedef struct s_ft_simple_map_static
{
	size_t							key_length;
	t_ft_simple_map_static_value	*values;
}	t_ft_simple_map_static;

typedef struct s_ft_simple_map_static_set_input
{
	t_ft_simple_map_static	*self;
	void					*key;
	void					*value;
}	t_ft_simple_map_static_set_input;

#endif
