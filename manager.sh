#!/bin/bash

#Zappy server daemon manager
#alcara_m

stop_zappy(){
    PID=`cut -d ":" -f 2 zappy.pid`
    kill -9 $PID
    echo "Server stopped with PID:$PID"
}

start_zappy(){
    if [ $# -eq 2 ]
    then
        ./server -d -p $2
    else
        ./server -d
    fi
    PID=`cut -d ":" -f 2 zappy.pid`
    echo "Server started with PID:$PID"
}

status_zappy(){
    PID=`cut -d ":" -f 2 zappy.pid`
    STATUS=`ps aux | grep $PID | wc -l`
    if [ $STATUS -eq 2 ]
    then
        echo "Zappy server is running"
    else
        echo "Zappy server is not running"
    fi
}

if [ $# -lt 1 ]
then
    echo "Usage: ./manager.sh [start, stop, status, restart] {PORT to start}"
    exit
fi

case "$1" in
'start')
    start_zappy
;;
'stop')
    stop_zappy
;;
'status')
    status_zappy
;;
'status')
    stop_zappy
    start_zappy
;;
esac