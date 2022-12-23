#########################################################################
# File Name: gen.sh
# Author: ghost_lzw
# mail: lanzongwei541@gmail.com
# Created Time: Sat Jan 23 20:34:58 2021
#########################################################################
#!/bin/bash
g++ std.cpp -o my -O2
data=./data
for file in $data/*
do
if [[ $file == *.in ]]
then
time ./my < $file > my.out
if diff -Z $data/$(basename "$file" .in).out my.out
then
printf AC
else
echo WA in $file
exit 0
fi
fi
done

