#!/usr/bin/env bash

cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nrk 1 | awk '{ print $2, $1 }'
