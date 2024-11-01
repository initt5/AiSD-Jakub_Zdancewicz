# python generator.py
import random
import sys

min_float = -1000000
max_float = 1000000

n = int(sys.argv[1]) # random.randint(10000, 100000)

with open("input.txt", "w") as test:
  test.write(f'{n}' + '\n')
  for i in range(n):
    test.write(f'{random.uniform(min_float, max_float)}')
    if i != n:
      test.write('\n')
