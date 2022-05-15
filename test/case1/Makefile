include ../common/prelude.mk

all: test
clean:
	$Q[ ! -d obj ] || rm -f obj/*.exe
fclean:
	$Qrm -rf obj
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
refresh: clean
retest:
	$Q$(MAKE) fclean
	$Q$(MAKE) test
test: refresh
	$Q$(MAKE) test_none
	$Q[ ! -f ../target/address.a ] || $(MAKE) test_address
	$Q[ ! -f ../target/memory.a ] || $(MAKE) test_memory
	$Q[ ! -f ../target/undefined.a ] || $(MAKE) test_undefined
.PHONY: all clean fclean re refresh retest test

VARIANTS := none address memory undefined

$(addprefix test_,$(VARIANTS)): test_%: obj/test_%.exe
	$Q./$<
obj/test_none.exe: ../target/none.a obj/none.a
	$Q$(CC) $(CFLAGS) -o $@ $^
obj/test_address.exe: ../target/address.a obj/address.a
	$Q$(CC) $(CFLAGS) -fsanitize=address -o $@ $^
obj/test_memory.exe: ../target/memory.a obj/memory.a
	$Q$(CC) $(CFLAGS) -fsanitize=memory -o $@ $^
obj/test_undefined.exe: ../target/undefined.a obj/undefined.a
	$Q$(CC) $(CFLAGS) -fsanitize=undefined -o $@ $^
obj/%.a: | obj/Makefile
	$Q$(MAKE) -C obj $(@F)
obj/Makefile:
	$Qmkdir -p obj
	$Qcp obj.mk obj/Makefile
.PHONY: test_none test_address test_memory test_undefined
