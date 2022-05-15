include ../common/prelude.mk

all: test
clean:
	$Qrm -rf tmp src obj
fclean: clean
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
refresh: fclean
	$Qcp -r ../../src tmp
	$Qmv tmp src
retest:
	$Q$(MAKE) fclean
	$Q$(MAKE) test
test: refresh
	$Q$(MAKE) refresh
	$Q$(MAKE) -f test.mk test
.PHONY: all clean fclean re refresh retest test
