CC = gcc

MAX_LITERAL = 65535

VARIABLES = __I __F0 __F1 __TMP R
TARGETS = $(VARIABLES:%=literal_%.h)

.PHONY: build
build: $(TARGETS)

.PHONY: clean
clean:
	rm -f $(TARGETS)

.PHONY: run
run: main.h build
ifeq ($(N),)
	@echo "ERROR: no input number specified"
	@echo "usage: make $@ N=<number>"
	@exit 1
endif
	$(CC) -E $< -DN=$(N) | grep -vE '#|^$$'

define LITERAL_template =
literal_$(1).h: gen_literal.sh
	./$$^ $(1) $(MAX_LITERAL) > $$@
endef

$(foreach _variable, $(VARIABLES),\
	$(eval $(call LITERAL_template,$(_variable))))
