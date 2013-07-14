#!/bin/bash
##
## manager.sh for zappy in /home/hero/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Jul 12 20:38:17 2013 Marin Alcaraz
## Last update Fri Jul 12 22:51:51 2013 Marin Alcaraz
##

verify_file()
{
    FILE_STAT=`cat zappy.pid 2>&1 /tmp/manager.log`
    if [ $? -eq 1 ]
    then
	FILE_STAT=1
    else
	FILE_STAT=0
    fi
}

stop_zappy()
{
    PID=`cut -d ":" -f 2 zappy.pid 2> /tmp/manager.log`
    if [ $? -eq 0 ]
    then
	kill -9 $PID
    fi
    rm zappy.pid 2> /tmp/manager.log
    if [ $? -eq 0 ]
    then
	echo "Server stopped with PID:$PID"
    else
	echo "There's no server running"
    fi
}

start_zappy()
{
    verify_file
    if [ $FILE_STAT -eq 1 ]
    then
	if [ $# -eq 2 ]
	then
            ./server -d -p $2 2> /tmp/manager.log
	else
            ./server -d 2> /tmp/manager.log
	fi
	if [ $? -eq 0 ]
	then
	    PID=`cut -d ":" -f 2 zappy.pid`
	    echo "Server started with PID:$PID"
	else
	    echo "Binary not found, try: make"
	fi
    else
	echo "Server is already running, please stop"
	exit
    fi
}

status_zappy()
{
    PID=`cut -d ":" -f 2 zappy.pid 2> /tmp/manager.log`
    STATUS=`ps aux | grep $PID | wc -l 2> /tmp/manager.log`
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
