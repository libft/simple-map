include ../common/prelude.mk

all: test
clean:
	$Q[ ! -d obj ] || rm -f obj/*.exe
fclean:
	$Qrm -rf obj
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
test:
	$Q$(MAKE) test_none
	$Q[ ! -f ../target/leak.a ] || $(MAKE) test_leak
	$Q[ ! -f ../target/address.a ] || $(MAKE) test_address
	$Q[ ! -f ../target/memory.a ] || $(MAKE) test_memory
	$Q[ ! -f ../target/undefined.a ] || $(MAKE) test_undefined
.PHONY: all clean fclean re test

CC := clang
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic -g3

$(addprefix test_,none leak address memory undefined): test_%: obj/test_%.exe
	$Q$(foreach t,$(shell find ../data/int_string -type f -name "*.csv"),./$< < $t && )true
obj/test_none.exe: obj/lib.none.a
	$Q$(CC) -o $@ ../target/none.a $^
obj/test_leak.exe: obj/lib.leak.a
	$Q$(CC) -o $@ ../target/leak.a $^
obj/test_address.exe: obj/lib.address.a
	$Q$(CC) -fsanitize=address -o $@ ../target/address.a $^
obj/test_memory.exe: obj/lib.memory.a
	$Q$(CC) -fsanitize=memory -o $@ ../target/memory.a $^
obj/test_undefined.exe: obj/lib.undefined.a
	$Q$(CC) -fsanitize=undefined -o $@ ../target/undefined.a $^
obj/%.a: | obj/Makefile
	$Q$(MAKE) -C obj $(@F)
obj/Makefile:
	$Qmkdir -p obj
	$Qcp obj.mk obj/Makefile
.PHONY: test_none test_address test_memory test_undefined
