#!/bin/bash

A=("a" "b" "c")

for i in {1..10}; do
  echo "${i}"
done

for char in ${A[@]}; do
  echo "${char}"
done
