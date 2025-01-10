# ./a < input.txt | python sprawdzarka.py
ans = 0
i = 0
length = 0
comparisons = 0
assignments = 0
for s in input().split():
  if i == 0:
    length = int(s)
    i += 1
  elif i == 1:
    ans = int(s)
    i += 1
  elif i == 2:
    assignments = int(s)
    i += 1
  elif i == 3:
    comparisons = int(s)
    i += 1
print(f"{length} {assignments} {comparisons} {ans}")