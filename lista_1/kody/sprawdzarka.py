# ./a < input.txt | python3 sprawdzarka.py
A = []
i = 0
length = 0
comparisons = 0
assignments = 0
for str in input().split():
  if i == 0:
    length = int(str)
    i += 1
  elif i == 1:
    assignments = int(str)
    i += 1
  elif i == 2:
    comparisons = int(str)
    i += 1
  else:
    A.append(float(str))
isSorted = sorted(A) == A
print(f"Czy posortowany? {isSorted} \nDlugość tablicy: {length} \nIlość przypisań: {assignments} \nIlość porównań: {comparisons}")
