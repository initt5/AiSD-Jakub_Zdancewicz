#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

int maximumNumber(int A[], int n)
{
  int max = A[0];
  assignments += 2;
  comparisons += 1;
  for (int i = 1; i < n; ++i)
  {
    comparisons += 2;
    assignments += 1;
    if (A[i] > max)
    {
      assignments += 1;
      max = A[i];
    }
  }
  return max;
}
void countingSort(int A[], int n, int d, int base)
{
  int C[d];
  int B[n];
  assignments += 3;
  comparisons += 1;
  for (int j = 0; j < d; ++j)
  {
    comparisons += 1;
    assignments += 2;
    C[j] = 0;
  }
  comparisons += 1;
  assignments += 1;
  for (int i = 0; i < n; ++i)
  {
    comparisons += 1;
    assignments += 2;
    ++C[(A[i] / base) % d];
  }
  comparisons += 1;
  assignments += 1;
  for (int j = 1; j < d; ++j)
  {
    comparisons += 1;
    assignments += 2;
    C[j] += C[j - 1];
  }
  comparisons += 1;
  assignments += 1;
  for (int i = n - 1; i > -1; --i)
  {
    comparisons += 1;
    assignments += 4;
    int digit = (A[i] / base) % d;
    B[C[digit] - 1] = A[i];
    --C[digit];
  }
  comparisons += 1;
  assignments += 1;
  for (int i = 0; i < n; ++i)
  {
    comparisons += 1;
    assignments += 2;
    A[i] = B[i];
  }
}

void radixSort(int A[], int n, int d)
{
  assignments += 1;
  int max = maximumNumber(A, n);
  comparisons += 1;
  assignments += 1;
  for (int base = 1; max / base > 0; base *= d)
  {
    comparisons += 1;
    assignments += 1;
    countingSort(A, n, d, base);
  }
}
void negativeRadixSort(int A[], int n, int d)
{
  int positive[n];
  int negative[n];
  int p = 0;
  int neg = 0;
  assignments += 5;
  comparisons += 1;
  for (int i = 0; i < n; ++i)
  {
    comparisons += 2;
    assignments += 1;
    if (A[i] >= 0)
    {
      positive[p] = A[i];
      ++p;
      assignments += 2;
    }
    else
    {
      negative[neg] = -A[i];
      ++neg;
      assignments += 2;
    }
  }
  radixSort(positive, p, d);
  radixSort(negative, neg, d);
  int index = 0;
  assignments += 2;
  comparisons += 1;
  for (int i = neg - 1; i > -1; --i)
  {
    comparisons += 1;
    A[index] = -negative[i];
    ++index;
    assignments += 3;
  }
  assignments += 1;
  comparisons += 1;
  for (int i = 0; i < p; ++i)
  {
    assignments += 3;
    comparisons += 1;
    A[index] = positive[i];
    ++index;
  }
}

int main()
{
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> A[i];
  }
  negativeRadixSort(A, n, 2);
  cout << n << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  for (int i = 0; i < n; ++i)
  {
    cout << std::fixed << A[i] << " ";
  }
  return 0;
}