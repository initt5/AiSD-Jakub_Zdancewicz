#include <iostream>
using namespace std;

struct Activity
{
  int start;
  int end;
};

int dp_activity_selector(Activity activities[], int n, int **c, int **act)
{
  for (int i = 0; i <= n + 1; ++i)
  {
    for (int j = 0; j <= n + 1; ++j)
    {
      c[i][j] = 0;
      act[i][j] = -1;
    }
  }

  for (int l = 2; l <= n + 1; ++l)
  {
    for (int i = 0; i <= n + 1 - l; ++i)
    {
      int j = i + l;
      c[i][j] = 0;
      for (int k = i + 1; k < j; ++k)
      {
        if (activities[i].end <= activities[k].start && activities[k].end <= activities[j].start && c[i][k] + c[k][j] + 1 > c[i][j])
        {
          c[i][j] = c[i][k] + c[k][j] + 1;
          act[i][j] = k;
        }
      }
    }
  }
  return c[0][n + 1];
}

void print_activities(Activity activities[], int **c, int **act, int i, int j)
{
  if (act[i][j] != -1)
  {
    int k = act[i][j];
    cout << "(" << activities[k].start << ", " << activities[k].end << ") ";
    print_activities(activities, c, act, i, k);
    print_activities(activities, c, act, k, j);
  }
}

int main()
{
  int n;
  cin >> n;
  Activity activities[n + 2];
  activities[0] = {0, 0};
  for (int i = 1; i < n + 1; i++)
  {
    cin >> activities[i].start >> activities[i].end;
  }
  activities[n + 1] = {INT_MAX, INT_MAX};
  int **c = new int *[n + 2];
  int **act = new int *[n + 2];
  for (int i = 0; i <= n + 1; ++i)
  {
    c[i] = new int[n + 2];
    act[i] = new int[n + 2];
  }

  int selected_count = dp_activity_selector(activities, n, c, act);
  cout << "Maksymalna liczba zajec: " << selected_count << endl;
  cout << "Wybrane zajecia: ";
  print_activities(activities, c, act, 0, n + 1);
  cout << endl;

  for (int i = 0; i <= n + 1; ++i)
  {
    delete[] c[i];
    delete[] act[i];
  }
  delete[] c;
  delete[] act;

  return 0;
}