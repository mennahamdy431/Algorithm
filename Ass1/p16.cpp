#include <iostream>
#include <map>
using namespace std;

void rearrange(int arr[], int n)
{
    map<int, int> duplicates;

    for (int i = 0; i < n; i++)
    {
        duplicates[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (duplicates.find(arr[i]) != duplicates.end())
        {
            int Count = duplicates[arr[i]];
            while (Count != 0) {
                Count--;
                cout << arr[i] << " ";
            }

            duplicates.erase(arr[i]);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    rearrange(arr , n);

    return 0;
}
