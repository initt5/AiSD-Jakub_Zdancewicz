import subprocess
import matplotlib.pyplot as plt
import numpy as np
import math
import sys

Y = []
params = [2, 5, 10, 100, 5005, 10000, 20000, 30003, 40000, 50005, 60000, 70007, 80000, 90009, 100000]
n = int(sys.argv[1])
mode = sys.argv[2]
for param in params:
    print(param)
    comparisons = []
    assignments = []
    for i in range(n):
      subprocess.run(f'python generator.py {param} {mode}')
      cmd1 = ['./a']
      
      with open('input.txt', 'r') as input_file:
          result = subprocess.run(cmd1, stdin=input_file, capture_output=True, text=True)

      cmd2 = ['python', 'sprawdzarka.py']
      check_result = subprocess.run(cmd2, input=result.stdout, capture_output=True, text=True)

      #print(f"Parametr: {param}, Wynik sprawdzarki: {check_result.stdout}")
      p = check_result.stdout.split(" ")
      print(p)
      assignments.append(int(p[8]))
      comparisons.append(int(p[11].strip()))
    spr = math.ceil(sum(assignments)/len(assignments))
    spp = math.ceil(sum(comparisons)/len(comparisons))
    Y.append(spr+spp)
    print(f'Wielkość tablicy: {param} \
    Średnia ilość przypisań: {spr} \
    Średnia ilość porównań: {spp} \
    Średnia ilość operacji: {spr+spp}')
print(Y)
plt.scatter(params, Y)
z = np.polyfit(params, Y, 2)
p = np.poly1d(z)
plt.plot(params, p(params))
plt.xlabel('Wielkość tablicy wejściowej')
plt.ylabel('Ilość operacji')
plt.show()
    
