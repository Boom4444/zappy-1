#!/usr/bin/sh

for i in `seq 100`
do
    ./a.out $i -h $1 -p $2 &
done