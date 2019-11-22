CC = gcc

MAX_LITERAL = 255

VARIABLES = B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 B10 B11 B12 B13 B14 B15 N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 K0 K1 K2 K3 K4 K5 K6 K7 K8 K9 K10 K11 K12 K13 K14 K15 T0 T1 T2 T3
TARGETS = $(VARIABLES:%=literals/%.h) literals/sbox.h sub_bytes.h add_round_key.h transform_block.h transform_key.h

.PHONY: build
build: $(TARGETS)

.PHONY: clean
clean:
	rm -f $(TARGETS)

.PHONY: run
run: main.h build
	$(CC) -E $< | grep -vE '#|^$$'

literals/sbox.h: gen_sbox.sh
	mkdir -p literals/
	./$^ > $@

sub_bytes.h: gen_sub_bytes.sh
	./$^ > $@

add_round_key.h: gen_add_round_key.sh
	./$^ > $@

transform_block.h: gen_transform.sh
	./$^ B > $@

transform_key.h: gen_transform.sh
	./$^ K > $@

define LITERAL_template =
literals/$(1).h: gen_literal.sh
	mkdir -p literals/
	./$$^ $(1) $(MAX_LITERAL) > $$@
endef

$(foreach _variable, $(VARIABLES),\
	$(eval $(call LITERAL_template,$(_variable))))
