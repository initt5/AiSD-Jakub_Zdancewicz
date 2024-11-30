#include <iomanip>
#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

struct indexPair
{
  int first;
  int second;
};

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
indexPair partition(double A[], int p, int k)
{
  comparisons += 1;
  if (A[p] > A[k])
  {
    swap(A[p], A[k]);
  }
  assignments += 5;
  double x = A[p];
  double y = A[k];
  int i = p;
  int j = k;
  int s = p + 1;
  comparisons += 1;
  while (s < j)
  {
    comparisons += 1;
    comparisons += 1;
    if (A[s] <= x)
    {
      ++i;
      swap(A[i], A[s]);
      ++s;
      assignments += 2;
    }
    else if (A[s] >= y)
    {
      --j;
      swap(A[j], A[s]);
      assignments += 1;
    }
    else
    {
      assignments += 1;
      ++s;
    }
  }
  swap(A[i], A[p]);
  swap(A[j], A[k]);
  indexPair pair;
  pair.first = i;
  pair.second = j;
  assignments += 3;
  return pair;
}
void quicksort(double A[], int p, int k)
{
  comparisons += 1;
  if (p < k)
  {
    assignments += 1;
    indexPair s = partition(A, p, k);
    quicksort(A, p, s.first - 1);
    quicksort(A, s.first + 1, s.second - 1);
    quicksort(A, s.second + 1, k);
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