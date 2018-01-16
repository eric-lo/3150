#!/bin/bash

for f in "$@"; do
	counter=0
	wc -l ${f}
	while read line; do
		(( counter ++ ))
		chars=$(echo -n ${line} | wc -c)
		words=$(echo -n ${line} | wc -w)
		echo "Line $((counter)): ${chars} chars, ${words} words"
	done < ${f}
done
