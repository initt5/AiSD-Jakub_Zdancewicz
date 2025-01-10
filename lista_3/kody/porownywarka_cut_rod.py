import subprocess
import math
import sys

def porownywarka(algorytm, param, mode):
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
params = [
    2, 5, 10, 15, 20, 25, 30, 55, 100, 505, 1000, 2003, 3000, 4000, 5001, 
    6007, 7000, 8000, 9009, 10000, 11009, 12000, 13000, 14000, 15000,
    16000, 17001, 18000, 19000, 20000
]
params = [i for i in range(1, 26)]
n = int(sys.argv[1])
mode = sys.argv[2]

for param in params:
    print(f"Długość danych wejściowych: {param}\n")
    comparisonsa = []
    assignmentsa = []
    comparisonsb = []
    assignmentsb = []
    comparisonsc = []
    assignmentsc = []
    aa = []  # Results of algorithm 'a'
    ab = []  # Results of algorithm 'b'
    ac = []  # Results of algorithm 'c'
    isGood = True
    
    for i in range(n):
        subprocess.run(f'python generator_cut_rod.py {param} {mode}')
        # If the param is small enough, perform comparisons for algorithm 'a'
        if param < 26:
            pa = porownywarka("a", param, mode)
            assignmentsa.append(int(pa[1]))
            comparisonsa.append(int(pa[2]))
            aa.append(pa[3])  # Store the result for algorithm 'a'
        
        # Perform comparisons for algorithm 'b'
        pb = porownywarka("b", param, mode)
        assignmentsb.append(int(pb[1]))
        comparisonsb.append(int(pb[2]))
        ab.append(pb[3])  # Store the result for algorithm 'b'

        # Perform comparisons for algorithm 'c'
        pc = porownywarka("c", param, mode)
        assignmentsc.append(int(pc[1]))
        comparisonsc.append(int(pc[2]))
        ac.append(pc[3])  # Store the result for algorithm 'c'
        
        # Check if the results are consistent across algorithms
        if ((pa[3] != pb[3] and param < 21) or (pa[3] != pc[3] and param < 21) or pb[3] != pc[3]):
            isGood = False
    
    # Safe average calculation function
    def safe_average(lst):
        return math.ceil(sum(lst) / len(lst)) if len(lst) > 0 else 0
    
    saa = safe_average(assignmentsa)
    sab = safe_average(assignmentsb)
    sac = safe_average(assignmentsc)
    spa = safe_average(comparisonsa)
    spb = safe_average(comparisonsb)
    spc = safe_average(comparisonsc)
    
    print(f"Czy działa tak samo? {isGood}\n")
    # Print results for each algorithm if there are valid comparisons
    if len(comparisonsa) > 0:
        print(f'Algorytm: naive\nŚrednia ilość przypisań: {saa}\nŚrednia ilość porównań: {spa}\nŚrednia ilość operacji: {saa + spa}\nWynik: {aa[-1] if aa else "Brak wyniku"}')
        Ya.append(saa + spa)
    
    print(f'Algorytm: memorized\nŚrednia ilość przypisań: {sab}\nŚrednia ilość porównań: {spb}\nŚrednia ilość operacji: {sab + spb}\nWynik: {ab[-1] if ab else "Brak wyniku"}')
    Yb.append(sab + spb)
    
    print(f'Algorytm: iterative\nŚrednia ilość przypisań: {sac}\nŚrednia ilość porównań: {spc}\nŚrednia ilość operacji: {sac + spc}\nWynik: {ac[-1] if ac else "Brak wyniku"}')
    Yc.append(sac + spc)

# Print the final results
print("Final results for naive algorithm (Ya):", Ya)
print("Final results for memorized algorithm (Yb):", Yb)
print("Final results for iterative algorithm (Yc):", Yc)