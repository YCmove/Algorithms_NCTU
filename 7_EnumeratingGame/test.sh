#!/bin/bash

g++ 7_EnumeratingGame_o2.cpp -Wall -o out && ./out < data_o4.txt &> data_5.txt
echo "===== start 4.cpp ====="
g++ 7_EnumeratingGame_4.cpp -Wall -o out && ./out < data_5.txt
# echo "===== start 2_TLE.cpp ====="
# g++ 7_EnumeratingGame_2_TLE.cpp -Wall -o out && ./out < data_5.txt