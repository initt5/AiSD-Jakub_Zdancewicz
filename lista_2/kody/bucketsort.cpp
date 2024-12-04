#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

struct Node
{
  Node *prev = nullptr;
  double key;
  Node *next = nullptr;
};
struct List
{
  Node *head = nullptr;
  void insert(Node *x)
  {
    comparisons += 1;
    if (this->head == nullptr)
    {
      assignments += 1;
      this->head = x;
      return;
    }
    Node *curr = this->head;
    assignments += 1;
    comparisons += 1;
    if (curr->key >= x->key)
    {
      assignments += 4;
      x->next = this->head;
      this->head->prev = x;
      x->prev = nullptr;
      this->head = x;
      return;
    }
    assignments += 1;
    comparisons += 2;
    while (curr->next != nullptr && curr->next->key < x->key)
    {
      comparisons += 2;
      assignments += 2;
      curr = curr->next;
    }
    comparisons += 1;
    if (curr->next == nullptr)
    {
      assignments += 3;
      curr->next = x;
      x->prev = curr;
      x->next = nullptr;
    }
    else
    {
      assignments += 4;
      x->next = curr->next;
      x->prev = curr;
      curr->next->prev = x;
      curr->next = x;
    }
  }
  void del(Node *x)
  {
    if (x->prev != nullptr)
    {
      x->prev->next = x->next;
    }
    else
    {
      this->head = x->next;
    }
    if (x->next != nullptr)
    {
      x->next->prev = x->prev;
    }
  }
  Node *search(double k)
  {
    Node *x = this->head;
    while (x != nullptr && x->key != k)
    {
      x = x->next;
    }
    return x;
  }
};
void bucketSort(double A[], int n)
{
  comparisons += 1;
  if (n <= 1)
  {
    return;
  }
  double min = A[0], max = A[0];
  assignments += 2;
  assignments += 1;
  comparisons += 1;
  for (int i = 1; i < n; i++)
  {
    comparisons += 1;
    comparisons += 2;
    if (A[i] < min)
      min = A[i];
    if (A[i] > max)
      max = A[i];
    assignments += 2;
  }
  assignments += 2;
  comparisons += 1;
  if (max == min)
  {
    return;
  }
  assignments += 1;
  double range = max - min;
  assignments += 1;
  List *B[n];
  assignments += 1;
  comparisons += 1;
  for (int i = 0; i < n + 1; ++i)
  {
    assignments += 2;
    comparisons += 1;
    B[i] = new List;
  }
  assignments += 1;
  comparisons += 1;
  for (int i = 0; i < n; ++i)
  {
    assignments += 1;
    comparisons += 5;
    Node *element = new Node;
    element->key = A[i];
    double normalized = (A[i] - min) / range;
    int index = int(normalized * n);
    assignments += 3;
    comparisons += 1;
    if (index == n)
    {
      --index;
      assignments += 1;
    }
    B[index]->insert(element);
  }
  int idx = 0;
  assignments += 2;
  comparisons += 1;
  for (int i = 0; i < n; ++i)
  {
    assignments += 4;
    comparisons += 2;
    Node *curr = B[i]->head;
    while (curr != nullptr)
    {
      comparisons += 1;
      assignments += 3;
      A[idx] = curr->key;
      ++idx;
      curr = curr->next;
    }
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
  bucketSort(A, n);
  cout << n << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  for (int i = 0; i < n; ++i)
  {
    cout << std::fixed << A[i] << " ";
  }
  return 0;
}