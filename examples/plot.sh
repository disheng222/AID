#!/bin/bash

i=1
for file in `ls hd-result/*.dat`
do
    if [ $i -lt 1000 ];then
    	fn=`echo $file | cut -d '.' -f 1`
    	export fname=$fn
    	com="gnuplot vplot.plg"
    	$com
	i=$[$i+1]
    else
	exit
    fi
done

