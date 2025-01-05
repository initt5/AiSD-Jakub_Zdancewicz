#include <iostream>
using namespace std;

struct Activity
{
  int start;
  int end;
};

int modified_activity_selector(Activity activities[], int n, Activity selected[])
{
  int k = n - 1;
  selected[0] = activities[k];
  int selected_count = 1;
  for (int m = n - 2; m > -1; --m)
  {
    if (activities[m].end <= activities[k].start)
    {
      selected[selected_count++] = activities[m];
      k = m;
    }
  }
  return selected_count;
}

int main()
{
  int n;
  cin >> n;
  Activity activities[n];
  for (int i = 0; i < n; i++)
  {
    cin >> activities[i].start >> activities[i].end;
  }
  Activity selected[n];
  int selected_count = modified_activity_selector(activities, n, selected);
  cout << "Dlugosc: " << selected_count << endl;
  cout << "Zajecia: ";
  for (int i = 0; i < selected_count; i++)
  {
    cout << "(" << selected[i].start << ", " << selected[i].end << ") ";
  }
  cout << endl;
  return 0;
}