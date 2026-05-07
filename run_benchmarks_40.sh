#!/bin/bash

echo "Budowanie projektu..."
mkdir -p build && cd build && cmake .. && make -j4 && cd ..
mkdir -p results

ITERATIONS=50

echo "=== Badanie A: Wplyw liczebnosci zbioru ==="
for algo in 3 4 5; do
  for struct in 0 1 2; do
    for size in 5000 10000 25000 50000; do
      echo "Running Badanie A: Algo=$algo Struct=$struct Size=$size"
      ./build/aizo --benchmark -a $algo -s $struct -t 0 -d 0 -l $size -n $ITERATIONS -r results/badanie_A.csv
    done
  done
done

echo "=== Badanie B: Wplyw rozkladu ==="
for struct in 0 2; do
  for dist in 0 1 2 3; do
    echo "Running Badanie B: Algo=5 Struct=$struct Dist=$dist Size=25000"
    ./build/aizo --benchmark -a 5 -s $struct -t 0 -d $dist -l 25000 -n $ITERATIONS -r results/badanie_B.csv
  done
done

echo "=== Badanie C: Wplyw typu danych ==="
for type in 0 1 5 3; do
  echo "Running Badanie C: Algo=5 Struct=0 Type=$type Size=25000"
  ./build/aizo --benchmark -a 5 -s 0 -t $type -d 0 -l 25000 -n $ITERATIONS -r results/badanie_C.csv
done

echo "=== Badanie Omega: Nieliniowe struktury danych ==="
for struct in 0 1 2 4; do
  echo "Running Badanie Omega: Algo=5 Struct=$struct Size=25000"
  ./build/aizo --benchmark -a 5 -s $struct -t 0 -d 0 -l 25000 -n $ITERATIONS -r results/badanie_Omega.csv
done

echo "Wszystkie benchmarki zakoczone! Pliki zostaly zapisane w folderze results/."
