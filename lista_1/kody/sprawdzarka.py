# ./a < input.txt | python3 sprawdzarka.py
A = []
for str in input().split():
  A.append(int(str))
if (sorted(A) == A):
  print(f"True, len: {len(A)}")
else:
  print(f"False, len: {len(A)}")