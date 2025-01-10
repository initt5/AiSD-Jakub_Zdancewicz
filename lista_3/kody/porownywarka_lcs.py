import subprocess
import math
import sys

def porownywarka(algorytm, param):
    cmd1 = [f'./{algorytm}']
    with open('input.txt', 'r') as input_file:
        result = subprocess.run(cmd1, stdin=input_file, capture_output=True, text=True)
    cmd2 = ['python', 'sprawdzarka.py']
    check_result = subprocess.run(cmd2, input=result.stdout, capture_output=True, text=True)
    p = check_result.stdout.split(" ")
    return p

Ya = []
Yb = []
Yc = []
params = [2, 5, 11, 50, 101, 200, 301, 500, 701, 1000, 1201, 1500, 1801, 2000, 2201, 2400, 2500, 2601, 3000]
n = int(sys.argv[1])

for param in params:
    print(f"Długość danych wejściowych: {param}\n")
    comparisonsa = []
    assignmentsa = []
    comparisonsb = []
    assignmentsb = []
    aa = []  # Results of algorithm 'a'
    ab = []  # Results of algorithm 'b'
    isGood = True
    
    for i in range(n):
        subprocess.run(f'python generator_lcs.py {param} {param}')
        # If the param is small enough, perform comparisons for algorithm 'a'      
        # Perform comparisons for algorithm 'b'
        pa = porownywarka("a", param)
        assignmentsa.append(int(pa[1]))
        comparisonsa.append(int(pa[2]))
        aa.append(pa[3])  # Store the result for algorithm 'b'

        # Perform comparisons for algorithm 'c'
        pb = porownywarka("b", param)
        assignmentsb.append(int(pb[1]))
        comparisonsb.append(int(pb[2]))
        ab.append(pb[3])  # Store the result for algorithm 'c'
        
        # Check if the results are consistent across algorithms
        if (pa[3] != pb[3]):
            isGood = False
    
    # Safe average calculation function
    def safe_average(lst):
        return math.ceil(sum(lst) / len(lst)) if len(lst) > 0 else 0
    
    saa = safe_average(assignmentsa)
    sab = safe_average(assignmentsb)
    spa = safe_average(comparisonsa)
    spb = safe_average(comparisonsb)
    
    print(f"Czy działa tak samo? {isGood}\n")
    # Print results for each algorithm if there are valid comparisons
    
    print(f'Algorytm: recursive\nŚrednia ilość przypisań: {saa}\nŚrednia ilość porównań: {spa}\nŚrednia ilość operacji: {saa + spa}\nWynik: {aa[-1] if aa else "Brak wyniku"}')
    Ya.append(saa + spa)

    print(f'Algorytm: iterative\nŚrednia ilość przypisań: {sab}\nŚrednia ilość porównań: {spb}\nŚrednia ilość operacji: {sab + spb}\nWynik: {ab[-1] if ab else "Brak wyniku"}')
    Yb.append(sab + spb)

# Print the final results
print("Final results for recursive algorithm (Ya):", Ya)
print("Final results for iterative algorithm (Yb):", Yb)