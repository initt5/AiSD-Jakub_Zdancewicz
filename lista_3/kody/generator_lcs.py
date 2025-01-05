# python generator_lcs.py 10 10
import random
import string
import sys

length_x = int(sys.argv[1])
length_y = int(sys.argv[2])

def generate_random_string(length):
    """Generuje losowy łańcuch znaków o zadanej długości."""
    return ''.join(random.choices(string.ascii_uppercase, k=length))

def create_test_input(file_name, length_x, length_y):
    """Tworzy plik z inputem testowym do algorytmu LCS."""
    X = generate_random_string(length_x)
    Y = generate_random_string(length_y)

    with open(file_name, 'w') as file:
        file.write((f"{length_x}\n"))
        file.write((f"{length_y}\n"))
        file.write(f"{X}\n")
        file.write(f"{Y}\n")

# Ustawienia
file_name = "input.txt"

# Generowanie pliku
create_test_input(file_name, length_x, length_y)