#include <iostream>
using namespace std;

unsigned long int assignments = 0;
unsigned long int comparisions = 0;

void insertion_sort2(float A[], int n)
{
  int size = n;
  assignments += 1;
  if (n % 2 == 0)
  {
    size -= 1;
    assignments += 1;
    comparisions += 1;
  }
  comparisions += 1;
  assignments += 1;
  for (int i = 1; i < size; i += 2)
  {
    assignments += 1;
    float max = A[i];
    float min = A[i + 1];
    assignments += 2;
    if (max < min)
    {
      float temp = max;
      max = min;
      min = temp;
      comparisions += 1;
      assignments += 3;
    }
    comparisions += 1;
    int j = i - 1;
    assignments += 1;
    comparisions += 2;
    while (j > -1 && A[j] > max)
    {
      comparisions += 2;
      A[j + 2] = A[j];
      --j;
      assignments += 2;
    }
    A[j + 2] = max;
    assignments += 1;
    comparisions += 2;
    while (j > -1 && A[j] > min)
    {
      comparisions += 2;
      A[j + 1] = A[j];
      --j;
      assignments += 2;
    }
    A[j + 1] = min;
    assignments += 1;
    comparisions += 1;
  }
  comparisions += 1;
  if (n % 2 == 0)
  {
    int j = n - 2;
    float key = A[n - 1];
    assignments += 2;
    comparisions += 2;
    while (j > -1 && A[j] > key)
    {
      comparisions += 2;
      A[j + 1] = A[j];
      --j;
      assignments += 2;
    }
    A[j + 1] = key;
    assignments += 1;
  }
}

int main()
{
  int n;
  cin >> n;
  float A[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> A[i];
  }
  insertion_sort2(A, n);
  cout << n << " ";
  cout << assignments << " ";
  cout << comparisions << " ";
  for (int i = 0; i < n; ++i)
  {
    cout << A[i] << " ";
  }
  return 0;
}