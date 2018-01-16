#!/bin/bash

# capture stdout
output=$(ls)
echo ""
echo "Output of ls: ${output}"

# where is the exit status?
echo ""
haha; echo "haha gives $?";

echo ""
echo "hello_world"; echo "echo gives $?"
