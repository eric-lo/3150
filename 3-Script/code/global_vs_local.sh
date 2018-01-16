#!/bin/bash

function print_vars {
	echo "global1: "${global1}
	echo "global2: "${global2}
	echo ""
	echo "local1:  "${local1}
}

global1="I am gloabl"

function foo {
	local local1="I am local"
	global2="I am also global"
	global1+=" :)"
	print_vars
	
}

echo "------- Before foo() -------"
print_vars
echo ""

echo "------- Inside foo() -------"
foo
echo ""

echo "------- After foo() -------"
print_vars
echo ""
