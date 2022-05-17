include ../../common/prelude.mk

CC := clang
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic -g3
CPPFLAGS := -I../../target
ARFLAGS := cr$(if $(filter 1,$(V) $(VERBOSE)),v,s)

SRCS := $(shell find ../src -maxdepth 1 -type f -name "*.c")

%.a:
	$Q$(AR) $(ARFLAGS) $@ $^

none.a: $(patsubst ../src/%.c,%.none.o,$(SRCS))
address.a: $(patsubst ../src/%.c,%.address.o,$(SRCS))
memory.a: $(patsubst ../src/%.c,%.memory.o,$(SRCS))
undefined.a: $(patsubst ../src/%.c,%.undefined.o,$(SRCS))

%.none.o: ../src/%.c
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
%.address.o: ../src/%.c
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) -fsanitize=address -c -o $@ $<
%.memory.o: ../src/%.c
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) -fsanitize=memory -c -o $@ $<
%.undefined.o: ../src/%.c
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) -fsanitize=undefined -c -o $@ $<

lib.none.a: $(patsubst ../src/%.c,%.none.o,$(SRCS))
lib.address.a: $(patsubst ../src/%.c,%.address.o,$(SRCS))
lib.memory.a: $(patsubst ../src/%.c,%.memory.o,$(SRCS))
lib.undefined.a: $(patsubst ../src/%.c,%.undefined.o,$(SRCS))
%.a:
	$Q$(AR) $(ARFLAGS) $@ $^
