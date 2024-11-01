import subprocess
import matplotlib.pyplot as plt
import numpy as np

Y = []
params = [2, 5, 10, 100, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
for param in params:
    comparisions = []
    assignments = []
    for i in range(10):
      subprocess.run(f'python3 generator.py {param}')
      cmd1 = ['./a']
      
      with open('input.txt', 'r') as input_file:
          result = subprocess.run(cmd1, stdin=input_file, capture_output=True, text=True)

      cmd2 = ['python3', 'sprawdzarka.py']
      check_result = subprocess.run(cmd2, input=result.stdout, capture_output=True, text=True)

      #print(f"Parametr: {param}, Wynik sprawdzarki: {check_result.stdout}")
      p = check_result.stdout.split(" ")
      print(p)
      comparisions.append(int(p[8]))
      assignments.append(int(p[11].strip()))
    Y.append((sum(comparisions)+sum(assignments))/(len(comparisions) + len(assignments)))
    print(param)
plt.scatter(params, Y)
z = np.polyfit(params, Y, 2)
p = np.poly1d(z)
plt.plot(params, p(params))
plt.xlabel('Wielkość tablicy wejściowej')
plt.ylabel('Ilość operacji')
plt.show()
    