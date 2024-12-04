# python generator.py
import random
import sys

min_float = 0#-1000000
max_float = 1#1000000

n = int(sys.argv[1]) # random.randint(10000, 100000)
mode = sys.argv[2]
with open("input.txt", "w") as test:
  test.write(f'{n}' + '\n')
  for i in range(n):
    if (mode == "int"):
      test.write(f'{random.randint(min_float, max_float)}') # python generator.py n int
      # test.write(f'{random.randint(0, max_float)}')
    elif (mode == "real"):
      test.write(f'{round(random.uniform(min_float, max_float), 6)}')
    if i != n:
      test.write('\n')
