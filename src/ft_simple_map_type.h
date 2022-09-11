/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_type.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:42:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/12 08:17:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLE_MAP_TYPE_H
# define FT_SIMPLE_MAP_TYPE_H

# include <limits.h>
# include <stddef.h>
# include <stdbool.h>

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

typedef struct s_ft_simple_map_dynamic
{
	void							*value;
	struct s_ft_simple_map_dynamic	*array[1 << CHAR_BIT];
}	t_ft_simple_map_dynamic;

typedef struct s_ft_simple_map_static_context_set
{
	t_ft_simple_map_static	*self;
	const void				*key;
	void					*value;
}	t_ft_simple_map_static_context_set;

typedef struct s_ft_simple_map_static_context_get
{
	t_ft_simple_map_static	*self;
	const void				*key;
	void					**out;
}	t_ft_simple_map_static_context_get;

#endif
