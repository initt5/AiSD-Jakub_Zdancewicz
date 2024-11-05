#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

void insertion_sort(float A[], int n)
{
  comparisons += 1;
  assignments += 1;
  for (int i = 1; i < n; ++i)
  {
    assignments += 1;
    float x = A[i];
    int j = i - 1;
    assignments += 2;
    comparisons += 2;
    while (j > -1 && A[j] > x)
    {
      A[j + 1] = A[j];
      --j;
      assignments += 2;
      comparisons += 2;
    }
    A[j + 1] = x;
    assignments += 1;
    comparisons += 1;
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
  insertion_sort(A, n);
  cout << n << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  for (int i = 0; i < n; ++i)
  {
    cout << std::fixed << A[i] << " ";
  }
  return 0;
}