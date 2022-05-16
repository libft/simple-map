include common/prelude.mk

CASES := $(sort $(wildcard case*))
COMMON_RULES := test clean fclean
CORES := $(shell sh scripts/nproc.sh)

all: test
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
.PHONY: all $(COMMON_RULES) re
define build_common_rule
$1:
	$Q$(foreach t,$(CASES),$(MAKE) -C $t -j $(CORES) $1 && )true
endef
$(foreach r, \
	$(COMMON_RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)
.PHONY: re

test: prepare_test
clean: prepare_clean
fclean: prepare_clean

.PHONY: prepare_clean
prepare_clean:
	$Qrm -rf tmp target

.PHONY: prepare_test
prepare_test: prepare_clean
	$Qcp -r ../src ./tmp
	$Qmv ./tmp ./target
	$Q$(MAKE) -f target.mk -j $(CORES) target/none.a
	-$Q$(MAKE) -f target.mk -j $(CORES) target/address.a
	-$Q$(MAKE) -f target.mk -j $(CORES) target/memory.a
	-$Q$(MAKE) -f target.mk -j $(CORES) target/undefined.a
	$Q$(MAKE) -f target.mk -j $(CORES) clean
