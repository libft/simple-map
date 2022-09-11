/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:42:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/12 08:16:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLE_MAP_H
# define FT_SIMPLE_MAP_H

# include <stddef.h>
# include <stdbool.h>

# include "ft_simple_map_type.h"

t_ft_simple_map_static	*new_ft_simple_map_static(
							size_t key_length);
void					ft_simple_map_static_free(
							t_ft_simple_map_static *self,
							void (*free_value)(void *value));
bool					ft_simple_map_static_set(
							t_ft_simple_map_static *self,
							const void *key,
							void *value);
bool					ft_simple_map_static_get(
							t_ft_simple_map_static *self,
							const void *key,
							void **out);
bool					ft_simple_map_static_pop(
							t_ft_simple_map_static *self,
							const void *key,
							void **out);
bool					ft_simple_map_static_iterate(
							t_ft_simple_map_static *self,
							void *context,
							bool (*f)(void *value, void *context));

t_ft_simple_map_dynamic	*new_ft_simple_map_dynamic(void);
void					ft_simple_map_dynamic_free(
							t_ft_simple_map_dynamic *self,
							void (*free_value)(void *value));
bool					ft_simple_map_dynamic_set(
							t_ft_simple_map_dynamic *self,
							const void *key,
							size_t key_length,
							void *value);
bool					ft_simple_map_dynamic_get(
							t_ft_simple_map_dynamic *self,
							const void *key,
							size_t key_length,
							void **out);
bool					ft_simple_map_dynamic_pop(
							t_ft_simple_map_dynamic *self,
							const void *key,
							size_t key_length,
							void **out);
bool					ft_simple_map_dynamic_iterate(
							t_ft_simple_map_dynamic *self,
							void *context,
							bool (*f)(void *value, void *context));

#endif
