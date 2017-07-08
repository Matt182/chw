#!/bin/bash

touch test_db
./ex17 test_db c
./ex17 test_db s 1 sam magnolia
echo $(pwd)
echo $(./ex17 test_db g 1)
./ex17 test_db s 2 george washington
./ex17 test_db s 3 nikole kidman
list="$(./ex17 test_db l)"
if [[ list == "1 sam magnolia\n2 george washington\n3 nikole kidman\n" ]]
then
	echo "list test is ok"
else
	echo "list FAILED!"
	echo "list is ${list}"
fi
rm test_db
