Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

CC ?= clang

all: test
clean:
	$Qrm -rf ./tmp
fclean:
	$Q$(MAKE) clean
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
test: $(shell cd src && find . -maxdepth 1 -type d -name "*.c")
.PHONY: all clean fclean re refresh retest test
