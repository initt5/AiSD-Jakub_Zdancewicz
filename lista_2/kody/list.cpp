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
    assignments += 2;
    x->next = this->head;
    x->prev = nullptr;
    comparisons += 1;
    if (this->head == nullptr)
    {
      assignments += 1;
      this->head = x;
    }
    else
    {
      assignments += 2;
      this->head->prev = x;
      this->head = x;
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

  void insertionSort()
  {
    comparisons += 2;
    if (this->head == nullptr || this->head->next == nullptr)
    {
      return;
    }
    assignments += 1;
    Node *curr = this->head->next;
    comparisons += 1;
    while (curr != nullptr)
    {
      comparisons += 1;
      assignments += 7;
      Node *x = curr;
      Node *y = curr->prev;
      curr = curr->next;
      comparisons += 1;
      if (x->prev != nullptr)
      {
        assignments += 1;
        x->prev->next = curr;
      }
      comparisons += 1;
      if (x->next != nullptr)
      {
        assignments += 1;
        x->next->prev = y;
      }
      comparisons += 2;
      while (y != nullptr && y->key > x->key)
      {
        assignments += 1;
        y = y->prev;
      }
      comparisons += 1;
      if (y == nullptr)
      {
        assignments += 4;
        this->head->prev = x;
        x->next = this->head;
        x->prev = nullptr;
        this->head = x;
      }
      else
      {
        assignments += 1;
        x->next = y->next;
        comparisons += 1;
        if (y->next != nullptr)
        {
          assignments += 1;
          y->next->prev = x;
        }
        assignments += 2;
        y->next = x;
        x->prev = y;
      }
    }
  }
};

int main()
{
  List L;
  assignments += 1;
  int n;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    double value;
    cin >> value;
    L.insert(new Node{nullptr, value, nullptr});
  }

  L.insertionSort();
  cout << n << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  Node *current = L.head;
  while (current != nullptr)
  {
    cout << std::fixed << current->key << " ";
    current = current->next;
  }

  return 0;
}