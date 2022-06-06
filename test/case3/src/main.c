/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:39:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 19:01:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ft_simple_map.h>

static t_ft_simple_map_dynamic	*g_map = NULL;

static void	clear(void)
{
	ft_simple_map_dynamic_free(g_map, free);
}

static bool	test_get(int key, bool expected_result, const char *value)
{
	char	*out;
	bool	result;

	result = ft_simple_map_dynamic_get(
			g_map,
			(void *)&key,
			sizeof(int),
			(void **)&out);
	return (result != expected_result || (!result && strcmp(out, value)));
}

static bool	test_set(int key, bool expected_result, const char *value)
{
	char *const	str = strdup(value);
	bool		result;

	if (!str)
		return (true);
	result = ft_simple_map_dynamic_set(
			g_map,
			(void *)&key,
			sizeof(int),
			(void *)str);
	return (result != expected_result);
}

static bool	test_pop(int key, bool expected_result, const char *value)
{
	char	*out;
	bool	result;
	bool	test_result;

	out = NULL;
	result = ft_simple_map_dynamic_pop(
			g_map,
			(void *)&key,
			sizeof(int),
			(void **)&out);
	test_result = (result != expected_result
			|| (!result && strcmp(out, value)));
	free(out);
	return (test_result);
}

int	main(int argc, char **argv)
{
	char	command[4];
	int		key;
	char	expected_result[6];
	char	value[1024];
	bool	parsed;

	if (argc == 2)
		freopen(argv[1], "r", stdin);
	atexit(clear);
	g_map = new_ft_simple_map_dynamic();
	if (!g_map)
		return (EXIT_FAILURE);
	while (scanf("\n%3[^,],%d,%5[^,],%1023[^\n]",
			command, &key, expected_result, value) == 4)
	{
		parsed = !strcmp(expected_result, "true");
		if ((!parsed && strcmp(expected_result, "false"))
			|| (!strcmp(command, "get") && test_get(key, parsed, value))
			|| (!strcmp(command, "set") && test_set(key, parsed, value))
			|| (!strcmp(command, "pop") && test_pop(key, parsed, value))
			|| (strcmp(command, "get") && strcmp(command, "set")
				&& strcmp(command, "pop")))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
