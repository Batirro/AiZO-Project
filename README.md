# Algorytmy i Złożoność Obliczeniowa - Projekt 1

Projekt realizowany w ramach przedmiotu Algorytmy i Złożoność Obliczeniowa. Celem projektu jest implementacja, zbadanie i porównanie efektywności różnych algorytmów sortowania dla wybranych, samodzielnie napisanych struktur danych.

## Zaimplementowane struktury danych
Wszystkie struktury alokują pamięć dynamicznie i zostały stworzone całkowicie od zera (bez użycia kontenerów z biblioteki standardowej STL takich jak `std::vector` czy `std::list`).
- **Array** (Tablica dynamiczna)
- **SinglyLinkedList** (Lista jednokierunkowa)
- **DoublyLinkedList** (Lista dwukierunkowa)
- **Stack** (Stos)

## Zaimplementowane algorytmy sortowania
- **Insertion Sort** (Sortowanie przez wstawianie)
- **Bucket Sort** (Sortowanie kubełkowe)
- **Quick Sort** (Sortowanie szybkie z podziałem Hoare'a)

## Wymagania
- Kompilator obsługujący standard **C++17** (np. GCC)
- System budowania **CMake** (wersja >= 3.10)
- Python 3 (do użycia skryptu generującego dane)

## Budowanie projektu
Projekt budowany jest za pomocą narzędzia CMake. Aby skompilować program, wykonaj w głównym katalogu projektu następujące polecenia:

```bash
mkdir -p build
cd build
cmake ..
make -j4
```
Plik wykonywalny `aizo` zostanie utworzony w katalogu `build/`.

## Instrukcja uruchamiania
Program obsługiwany jest z poziomu wiersza poleceń i posiada trzy główne tryby działania:

### 1. Tryb pomocy (Help)
Wyświetla szczegółową instrukcję i dostępne parametry:
```bash
./build/aizo --help
```

### 2. Tryb pojedynczego pliku (Single File)
Służy do sortowania danych z podanego pliku i zapisywania wyników.
Przykład: Sortowanie pliku wejściowego przy użyciu QuickSort (5) dla Tablicy (0) z zapisem do pliku wyjściowego:
```bash
./build/aizo --singleFile -i data/random_10000.txt -o data/sorted_output.txt -a 5 -s 0 -t 0
```

### 3. Tryb badań (Benchmark)
Uruchamia wybraną procedurę badawczą zadanką ilość razy, uśrednia czas i zapisuje wynik do pliku `.csv`.
Przykład: 50 iteracji QuickSorta dla Tablicy, 25000 elementów:
```bash
./build/aizo --benchmark -a 5 -s 0 -t 0 -d 0 -l 25000 -n 50 -r results/wyniki.csv
```

## Narzędzia pomocnicze

### Generator danych (`tools/generator.py`)
Skrypt w języku Python generujący pliki tekstowe z liczbami losowymi, posortowanymi rosnąco oraz malejąco. Służy do przygotowania środowiska przed uruchomieniem algorytmów.
```bash
cd tools
python3 generator.py
```

### Skrypt badawczy (`run_benchmarks_40.sh`)
Gotowy skrypt automatyzujący całą serię badań (Badanie A, B, C oraz Omega) wymaganych do sprawozdania laboratoryjnego. Samodzielnie kompiluje projekt, przeprowadza dziesiątki tysięcy testów i zapisuje uśrednione wyniki w katalogu `results/`.
```bash
./run_benchmarks_40.sh
```
