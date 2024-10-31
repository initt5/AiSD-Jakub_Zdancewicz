# python generator.py
import random
import sys

min_float = -1000000
max_float = 1000000

with open("input.txt", "w") as test:
  n = random.randint(1000, 10000)
  test.write(f'{n}' + '\n')
  for i in range(n):
    test.write(f'{random.randint(min_float, max_float)}')
    if i != n:
      test.write('\n')
