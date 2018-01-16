#!/bin/bash

# declare an array with four items
myarray=("three" 1 "five" 0)

# show its content
echo "Content of myarray before update:"
echo "${myarray[0]}"
echo "${myarray[1]}"
echo "${myarray[2]}"
echo "${myarray[3]}"
echo ""

# replace the third item
myarray[2]="eight"

# assign a new item (index discontinued)
myarray[5]="!"

# show its content
echo "Content of myarray after update:"
echo "${myarray[0]}"
echo "${myarray[1]}"
echo "${myarray[2]}"
echo "${myarray[3]}"
echo "${myarray[5]}"
echo ""

# show its content in form of a string
echo "Content \${myarray[@]}: ${myarray[@]}"
echo ""

# show the number of items inside
echo "Number of items: ${#myarray[@]}"
echo ""

# show the keys used in the array
echo "Keys in \${myarray[@]}: ${!myarray[@]}"
