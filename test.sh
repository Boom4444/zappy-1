#!/usr/bin/sh

for i in `seq 50`
do
    ./a.out $i -h $1 -p $2 &
done