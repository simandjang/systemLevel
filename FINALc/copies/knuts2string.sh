#!/bin/bash
awk '{
flag = $0 < 0 ? -1 : 1
gsub("-", "", $0)
knt = $0 % 17
next1 = int($0 / 17)
sck = next1 % 23
gal = flag * int(next1 / 23)
printf "%d/%d/%d\n", gal, sck, knt 
}' lab3data_r.txt
