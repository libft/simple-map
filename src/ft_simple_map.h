/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:42:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/12 01:57:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLE_MAP_H
# define FT_SIMPLE_MAP_H

# include <stddef.h>
# include <stdbool.h>

struct s_ft_simple_map_static	*new_ft_simple_map_static(size_t key_length);
bool							ft_simple_map_static_set(
									struct s_ft_simple_map_static *map,
									void *key,
									void *value);
bool							ft_simple_map_static_get(
									struct s_ft_simple_map_static *map,
									void *key,
									void **out);
bool							ft_simple_map_static_pop(
									struct s_ft_simple_map_static *map,
									void *key,
									void **out);

#endif
