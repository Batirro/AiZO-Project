import os
import random


def generateFile(fileName, size, dataType="random"):
    if dataType == "random":
        data = [random.randint(-10000, 10000) for _ in range(size)]
    elif dataType == "sorted":
        data = list(range(1, size + 1))
    elif dataType == "reverse":
        data = list(range(size, 0, -1))
    else:
        raise ValueError("Nieznany typ danych.")

    with open(fileName, "w") as f:
        f.write(f"{size}\n")
        for num in data:
            f.write(f"{num}\n")


if __name__ == "__main__":
    os.makedirs("../data", exist_ok=True)

    sizes = [10000, 50000, 100000, 250000, 500000, 1000000]

    for s in sizes:
        generateFile(f"../data/random_{s}.txt", s, "random")
        generateFile(f"../data/sorted_{s}.txt", s, "sorted")
        generateFile(f"../data/reverse_{s}.txt", s, "reverse")

    print("Pliki zostały wygenerowane w katalogu '../data'.")
