#!/bin/bash
v="$1"
for i in $(seq 0 15); do
    echo "#define N${i}_NEXT ${v}${i}_NEXT"
    echo "#include \"literals/N${i}.h\""
done
for i in $(seq 0 15); do
    echo "#undef ${v}${i}_NEXT"
    echo "#define ${v}${i}_NEXT N${i}"
    echo "#include \"literals/${v}${i}.h\""
done
