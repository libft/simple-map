include common/prelude.mk

CC := clang
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic
ARFLAGS := cr$(if $(filter 1,$(V) $(VERBOSE)),v,s)

.PHONY: clean
clean:
	$Qrm -rf target/*.o

SRCS := $(shell cd target && find . -maxdepth 1 -type f -name "*.c")

target/%.a:
	$Q$(AR) $(ARFLAGS) $@ $^

target/none.a: $(addprefix target/,$(SRCS:.c=.none.o))
target/address.a: $(addprefix target/,$(SRCS:.c=.address.o))
target/memory.a: $(addprefix target/,$(SRCS:.c=.memory.o))
target/undefined.a: $(addprefix target/,$(SRCS:.c=.undefined.o))

target/%.none.o: target/%.c
	$Q$(CC) $(CFLAGS) -c -o $@ $<
target/%.address.o: target/%.c
	$Q$(CC) $(CFLAGS) -fsanitize=address -c -o $@ $<
target/%.memory.o: target/%.c
	$Q$(CC) $(CFLAGS) -fsanitize=memory -c -o $@ $<
target/%.undefined.o: target/%.c
	$Q$(CC) $(CFLAGS) -fsanitize=undefined -c -o $@ $<
