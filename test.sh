#!/usr/bin/sh

for i in `seq 500`
do
    ./a.out $i -h $1 -p $2 &
done