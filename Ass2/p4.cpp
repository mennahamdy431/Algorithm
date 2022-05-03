#include <bits/stdc++.h>
using namespace std;

struct Activitiy
{
    int start;
    int finish;
};

//this function to make us enable to compare two objects
bool Activity_Compare(Activitiy activity1, Activitiy activity2)
{
    if(activity1.finish < activity2.finish)
    {
         return true;
    }
    else
    {
       return false;
    }

}

void getMaxActivities(Activitiy arr[], int n)
{
    sort(arr, arr+n, Activity_Compare);

    int i = 0;
    cout << "{" << arr[i].start << "," << arr[i].finish << "},";

    for (int j = 1; j < n; j++)
    {
      if (arr[j].start >= arr[i].finish)
      {
          cout << "{" << arr[j].start << ","
              << arr[j].finish << "},";
          i = j;
      }
    }
}


int main()
{
    Activitiy arr[] = {{1, 4}, {3, 5}, {0, 6}, {5, 7},
                      {3, 8}, {5, 9},{6,10},{8,11},{8,12},{2,13},{12,14}};
    int Size = sizeof(arr)/sizeof(arr[0]);
    getMaxActivities(arr, Size);
    return 0;
}
