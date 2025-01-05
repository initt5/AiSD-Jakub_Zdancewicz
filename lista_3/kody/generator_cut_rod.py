# python generator_cut_rod.py 100 sort
import random
import sys

max_price = 100

def generate_cut_rod_test(rod_length=10, sorted_mode=False):
    """
    Generates test cases for the cut rod algorithm.
    
    Parameters:
    - max_length: int, maximum length of the rod for any test case
    - max_price: int, maximum price for a segment of length i
    - sorted: bool, should tests be sorted in ascending order
    
    Returns:
    - file with test case
    """
    with open("input.txt", "w") as test:
      n = rod_length
      test.write(f'{n}' + '\n')
      cases = []
      for i in range(n):
        cases.append(random.randint(1, n))
      if sorted_mode:
        cases.sort()
      for i in range(n):
        test.write(f'{cases[i]}')
        if i != n:
          test.write('\n')

def main():
    rod_length = int(sys.argv[1])
    sorted_mode = False
    if len(sys.argv) > 2 and sys.argv[2] == "sort":
      sorted_mode = True
    test_cases = generate_cut_rod_test(rod_length, sorted_mode) 

if __name__ == "__main__":
    main()
