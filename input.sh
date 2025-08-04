#!/bin/bash

echo "Your firstname please: "
read fname;
echo "Hello $fname"

echo "Marks for maths: "
read math;

echo "Marks for ds:"
read ds;

echo "Marks os :"
read os;

avg=$(((math + ds + os) / 3 ));
echo "Avg: $avg";

if [ 4 -gt 3 ]; then
	echo Greater
else 
	echo Lesser
fi 
