/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:04:36 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/17 17:06:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "leak_test/include/ft/leak_test.h"

#include "test.h"

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
