#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Usage: $0 <target memory size>"
	exit 1
fi

BINDIR=`dirname $0`
pushd $BINDIR > /dev/null

TARGET=$1

MA=`cat /proc/meminfo | grep MemAvailable | awk '{print $2}'`
MA=$(($MA*1024))

if [ $TARGET -gt $MA ]
then
	echo "target is larger than free: $TARGET > $MA"
	exit 1
fi

TOHOLD=$(($MA - $TARGET))
echo "hold $TOHOLD bytes"

make
echo "lock $TOHOLD bytes..."
./domlock $TOHOLD

popd > /dev/null
