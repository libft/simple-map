include ../common/prelude.mk

SRCS := $(shell cd src && find . -maxdepth 1 -type f -name "*.c")

CC ?= clang
CFLAGS ?= -Wall -Wextra -Werror -std=c99 -pedantic

.PHONY: test
test: $(addprefix obj/, $(SRCS:.c=.o))
obj/%.o: src/%.c | obj
	$Q$(CC) $(CFLAGS) -c -o $@ $<
obj:
	$Qmkdir obj
