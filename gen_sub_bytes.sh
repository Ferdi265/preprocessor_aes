#!/bin/bash
for i in $(seq 0 15); do
    echo "#define SBOX_NEXT B${i}"
    echo "#include \"literals/sbox.h\""
    echo "#define B${i}_NEXT SBOX"
    echo "#include \"literals/B${i}.h\""
done
