#!/bin/bash

A=0

while [ $((A)) -lt 10 ]; do
  echo $((A))
  (( A++ ))
done
