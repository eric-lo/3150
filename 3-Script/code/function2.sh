#!/bin/bash

function addition {
  result=$(($1 + $2))
  echo "$1+$2=${result}"
}

addition "$@"
