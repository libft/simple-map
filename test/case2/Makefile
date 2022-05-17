include ../common/prelude.mk

all: test
clean:
	$Qrm -f test.exe
fclean: clean
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
test: test.exe
	$Q$(foreach t,$(shell find ../data/int_string -type f -name "*.csv"),./$< $t && )true
init: leak_test
deinit: fclean
	$Qrm -rf leak_test
.PHONY: all clean fclean re test init deinit

CC := clang
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic
CPPFLAGS := -I../target -g3

leak_test/libft_leak_test.none.a: leak_test
	$Q$(MAKE) -C $(@D) $(@F)
test.exe: leak_test/libft_leak_test.none.a ../target/none.a
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(shell find . -maxdepth 1 -type f -name "*.c") $^
leak_test:
	$Qsh ./init.sh
