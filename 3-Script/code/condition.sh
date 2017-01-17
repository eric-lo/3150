#!/bin/bash

A=1

if [ $((A)) -eq 0 ]; then
	echo "A equals to 0"
elif [ $((A)) -gt 0 ]; then
	echo "A is greater than 0"
else
	echo "A is smaller than 0"
fi
