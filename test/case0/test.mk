include ../common/prelude.mk

SRCS := $(shell cd src && find . -maxdepth 1 -type f -name "*.c")

CC := clang
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic
NORMINETTE = norminette

.PHONY: test
test: $(addprefix obj/, $(SRCS:.c=.o))
obj/%.o: src/%.c | obj
	$Q$(NORMINETTE) $<
	$Q$(CC) $(CFLAGS) -c -o $@ $<
obj:
	$Qmkdir obj
