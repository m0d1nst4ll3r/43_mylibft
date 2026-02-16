#!/bin/bash

min=$1
max=$2
max_jobs=${3:-4}
running=0

for ((arg = min; arg <= max; arg++)); do
	./a.out $arg &
	((running++))
	if ((running >= max_jobs)); then
		wait -n
		((running --))
	fi
done

wait
