/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:58:57 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/17 16:38:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ft_simple_map.h>
#include "leak_test/include/ft/leak_test.h"

static bool	test_get(
	t_ft_simple_map_static *map,
	int key,
	bool e,
	const char *value
)
{
	char	*out;
	bool	result;

	printf("test_get(%d, %s)\n", key, value);
	leak_test_start();
	result = ft_simple_map_static_get(map, (void *)&key, (void **)&out);
	leak_test_end();
	return (result != e || (!result && !strcmp(out, value)));
}

static bool	test_set(
	t_ft_simple_map_static *map,
	int key,
	bool e,
	const char *value
)
{
	char *const	str = strdup(value);
	bool		result;

	printf("test_set(%d, %s)\n", key, value);
	if (!str)
		return (true);
	leak_test_start();
	result = ft_simple_map_static_set(map, (void *)&key, (void *)str);
	leak_test_end();
	return (result != e);
}

static bool	test_pop(
	t_ft_simple_map_static *map,
	int key,
	bool e,
	const char *value
)
{
	char	*out;
	bool	result;
	bool	test_result;

	printf("test_pop(%d, %s)\n", key, value);
	out = NULL;
	leak_test_start();
	result = ft_simple_map_static_pop(map, (void *)&key, (void **)&out);
	leak_test_end();
	test_result = (result != e
			|| (!result && !strcmp(out, value)));
	free(out);
	return (test_result);
}

bool	test(FILE *f)
{
	char					c[4];
	int						key;
	char					r[6];
	char					v[1024];
	t_ft_simple_map_static	*m;

	fseek(f, 0, SEEK_SET);
	leak_test_start();
	m = new_ft_simple_map_static(sizeof(int));
	leak_test_end();
	if (!m)
		return (true);
	while (fscanf(f, "\n%3[^,],%d,%5[^,],%1000[^\n]", c, &key, r, v) == 4)
	{
		if ((strcmp(r, "true") && strcmp(r, "false"))
			|| (!strcmp(c, "get") && test_get(m, key, !strcmp(r, "true"), v))
			|| (!strcmp(c, "set") && test_set(m, key, !strcmp(r, "true"), v))
			|| (!strcmp(c, "pop") && test_pop(m, key, !strcmp(r, "true"), v))
			|| (strcmp(c, "get") && strcmp(c, "set") && strcmp(c, "pop")))
			return (true);
	}
	leak_test_start();
	ft_simple_map_static_free(m, free);
	return (false);
}

int	main(int argc, char **argv)
{
	FILE	*f;
	int		result;

	if (argc != 2)
		return (EXIT_FAILURE);
	f = fopen(argv[1], "r+");
	if (!f)
		return (EXIT_FAILURE);
	result = leak_test((bool (*)(const void *))test, (void *)f, NULL);
	fclose(f);
	if (result)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
