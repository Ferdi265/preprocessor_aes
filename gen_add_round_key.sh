#!/bin/bash
for i in $(seq 0 15); do
    echo "#define B${i}_NEXT (B${i} ^ K${i})"
    echo "#include \"literals/B${i}.h\""
done
