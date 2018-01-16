#!/bin/bash

mylongstr="this is a long string"

echo "My string: ${mylongstr}"
echo ""

echo "Number of characters in string: ${#mylongstr}"
echo ""

echo "Splitting my string like an array:"
for word in ${mylongstr[@]}; do
	echo "${word}"
done
echo ""
