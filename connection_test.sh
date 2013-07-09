#!/bin/bash

for i in `seq 11`;
do
   echo -e "Team 1\n" | nc 127.0.0.1 $1 &
done

