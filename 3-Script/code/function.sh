#!/bin/bash

function addition {
  result=$(($1 + $2))
}

function main {
	local a=1
	local b=2
	result=
	addition ${a} ${b}
	echo "${a}+${b}=${result}"
}

main
