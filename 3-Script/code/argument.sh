#!/bin/bash

echo "You called $0, with"

if [ $# -eq 0 ]; then
	echo "no arguments..."
	exit 0
fi

counter=0
for i in "$@"; do
	(( counter++ ))
	echo "Arg[${counter}]: ${i}"
done
