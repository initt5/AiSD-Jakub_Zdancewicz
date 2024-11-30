# ./a < input.txt | python3 sprawdzarka.py
A = []
i = 0
length = 0
comparisons = 0
assignments = 0
for s in input().split():
  if i == 0:
    length = int(s)
    i += 1
  elif i == 1:
    assignments = int(s)
    i += 1
  elif i == 2:
    comparisons = int(s)
    i += 1
  else:
    A.append(float(s))
B = []
with open('input.txt', 'r') as input_file:
  next(input_file)
  while line := input_file.readline():
    B.append(float(line.rstrip()))
isSorted = sorted(B) == A
print(f"Czy posortowany? {isSorted} \nDlugość tablicy: {length} \nIlość przypisań: {assignments} \nIlość porównań: {comparisons}")
"""
for i in range(len(B)):
  if (sorted(B)[i] != A[i]):
    print(i)
"""
