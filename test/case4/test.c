/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:03:27 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 19:48:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ft_simple_map.h>

#include "leak_test/include/ft/leak_test.h"

#include "test.h"

static void	test_free(void *ptr)
{
	leak_test_end();
	free(ptr);
	leak_test_start();
}

static bool	test_get(
	t_ft_simple_map_dynamic *map,
	int key,
	bool e,
	const char *value
)
{
	char	*out;
	bool	result;
	bool	test_result;

	leak_test_start();
	result = ft_simple_map_dynamic_get(
			map,
			(void *)&key,
			sizeof(int),
			(void **)&out);
	leak_test_end();
	test_result = (result != e || (!result && strcmp(out, value)));
	return (test_result);
}

static bool	test_set(
	t_ft_simple_map_dynamic *map,
	int key,
	bool e,
	const char *value
)
{
	char *const	str = strdup(value);
	bool		result;
	bool		test_result;

	if (!str)
		exit(EXIT_FAILURE);
	leak_test_start();
	result = ft_simple_map_dynamic_set(map,
			(void *)&key,
			sizeof(int),
			(void *)str);
	leak_test_end();
	test_result = result != e;
	return (test_result);
}

static bool	test_pop(
	t_ft_simple_map_dynamic *map,
	int key,
	bool e,
	const char *value
)
{
	char	*out;
	bool	result;
	bool	test_result;

	out = NULL;
	leak_test_start();
	result = ft_simple_map_dynamic_pop(
			map,
			(void *)&key,
			sizeof(int),
			(void **)&out);
	leak_test_end();
	test_result = (result != e || (!result && strcmp(out, value)));
	free(out);
	return (test_result);
}

bool	test(FILE *f)
{
	char					c[4];
	int						key;
	char					r[6];
	char					v[1024];
	t_ft_simple_map_dynamic	*m;

	fseek(f, 0, SEEK_SET);
	leak_test_start();
	m = new_ft_simple_map_dynamic();
	leak_test_end();
	if (!m)
		return (false);
	while (fscanf(f, "\n%3[^,],%d,%5[^,],%1000[^\n]", c, &key, r, v) == 4)
	{
		if ((strcmp(r, "true") && strcmp(r, "false"))
			|| (!strcmp(c, "get") && test_get(m, key, !strcmp(r, "true"), v))
			|| (!strcmp(c, "set") && test_set(m, key, !strcmp(r, "true"), v))
			|| (!strcmp(c, "pop") && test_pop(m, key, !strcmp(r, "true"), v))
			|| (strcmp(c, "get") && strcmp(c, "set") && strcmp(c, "pop")))
			break ;
	}
	leak_test_start();
	ft_simple_map_dynamic_free(m, test_free);
	return (false);
}
