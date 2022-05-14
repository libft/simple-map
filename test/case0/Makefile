include ../common/prelude.mk

all: test
clean:
	$Qrm -rf ./tmp ./obj
fclean: clean
	$Qrm -rf ./src
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
refresh:
	$Qrm -rf ./src
	$Qcp -r ../../src ./tmp
	$Qmv ./tmp ./src
retest:
	$Q$(MAKE) refresh
	$Q$(MAKE) test
test:
	$Q$(MAKE) refresh
	$Q$(MAKE) -f test.mk test
.PHONY: all clean fclean re refresh retest test
