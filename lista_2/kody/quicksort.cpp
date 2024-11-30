#include <iomanip>
#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

void swap(double &a, double &b)
{
  comparisons += 1;
  if (a != b)
  {
    double temp = a;
    a = b;
    b = temp;
    assignments += 3;
  }
}
int partition(double A[], int p, int k)
{
  double x = A[k];
  int i = p - 1;
  assignments += 3;
  comparisons += 1;
  for (int j = p; j < k; ++j)
  {
    comparisons += 2;
    assignments += 1;
    if (A[j] <= x)
    {
      assignments += 1;
      i += 1;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[k]);
  return i + 1;
}
void quicksort(double A[], int p, int k)
{
  comparisons += 1;
  if (p < k)
  {
    assignments += 1;
    int s = partition(A, p, k);
    quicksort(A, p, s - 1);
    quicksort(A, s + 1, k);
  }
}
int main()
{
  int n;
  cin >> n;
  double A[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> A[i];
  }
  quicksort(A, 0, n - 1);
  cout << n << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  for (int i = 0; i < n; ++i)
  {
    cout << std::fixed << A[i] << " ";
  }
  return 0;
}