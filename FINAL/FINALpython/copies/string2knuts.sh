#!/bin/bash

awk '{
split($0,arr,"/");
flag = arr[1] < 0 ? -1: 1
gsub("-", "", arr[1])
print flag*(arr[1]*23*17 + arr[2]*17 + arr[3]) 



}' ./lab3data.txt
