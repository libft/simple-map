all: libft_simple_map.a
libft_simple_map.a: .build/Makefile
	(cd .build && make)
	cp .build/libft_simple_map.a libft_simple_map.a
.build/Makefile: .build/sources.txt .build/sources.mk .build/objects.mk
	printf "libft_simple_map.a: %s\n\tar crs libft_simple_map.a %s\n\n" "$$(sed "s/\$$/.o/" < .build/sources.txt | xargs)" "$$(sed "s/\$$/.o/" < .build/sources.txt | xargs)" | cat - .build/sources.mk .build/objects.mk > .build/Makefile
.build/sources.mk: .build/sources.txt .build/headers.txt
	sed "s/\$$/.c/" < .build/sources.txt | cat - .build/headers.txt | xargs -I {} printf "%s: ../src/%s\n\tcp ../src/%s %s\n" {} {} {} {} > .build/sources.mk
.build/objects.mk: .build/headers.txt .build/sources.txt
	xargs -I {} printf "{}.o: {}.c %s\n\tcc -c {}.c\n" "$$(xargs < .build/headers.txt)" < .build/sources.txt > .build/objects.mk
.build/headers.txt: .build src
	find src -maxdepth 1 -type f -name '*.h' | sed "s#^src/##" > .build/headers.txt
.build/sources.txt: .build src
	find src -maxdepth 1 -type f -name '*.c' | sed "s#^src/##" | sed "s/\\.c\$$//" > .build/sources.txt
.build:
	mkdir -p .build
clean:
	rm -rf .build
fclean: clean
	rm -f libft_simple_map.a
.PHONY: all clean fclean libft_simple_map.a
