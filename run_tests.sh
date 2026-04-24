#!/bin/bash

# Upewniamy się, że projekt jest zbudowany
if [ ! -f "build/aizo" ]; then
    echo "Kompilowanie projektu..."
    mkdir -p build && cd build && cmake .. && make && cd ..
fi

# Biblioteka od prowadzącego wymaga tej zmiennej środowiskowej
export LD_LIBRARY_PATH=./libs/params/lib

echo "==========================================="
echo "   Test 1: Single File Mode (Array + int + QuickSort)"
echo "==========================================="
# Generowanie testowego pliku z 5 losowymi elementami
cat << 'DATA' > data.txt
5
76
-142
0
2138
-4
DATA

./build/aizo --singleFile --inputFile data.txt --outputFile posortowane.txt -a 5 -s 0 -t 0
echo "Zajrzyj do pliku 'posortowane.txt' aby zobaczyc wynik!"

echo ""
echo "==========================================="
echo "   Test 2: Benchmark Mode (Badanie A - Wpływ Liczebności)"
echo "==========================================="
# Wiele iteracji (10), lista dwukierunkowa, insertion sort
./build/aizo --benchmark -a 3 -s 2 -t 0 -d 0 -l 1000 -n 10 -r "results.csv"

echo ""
echo "==========================================="
echo "   Test 3: Benchmark Mode (Badanie C - Różne typy, float)"
echo "==========================================="
# 10 iteracji, float array, quick sort
./build/aizo --benchmark -a 5 -s 0 -t 1 -d 0 -l 5000 -n 10 -r "results.csv"

echo ""
echo "==========================================="
echo "Oto wygenerowany fragment pliku CSV:"
cat results.csv
echo "==========================================="
